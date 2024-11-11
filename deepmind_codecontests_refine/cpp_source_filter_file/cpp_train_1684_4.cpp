#include <bits/stdc++.h>
using namespace std;
const int segSize = 1 << 17;
const int segArraySize = 2 * segSize - 1;
const int segOff = segSize - 1;
int seg[segArraySize];
int segQuery(int a, int b, int i = 0, int l = 0, int r = segSize - 1) {
  if (b < l || a > r) return 0;
  if (a <= l && b >= r) return seg[i];
  return segQuery(a, b, (2 * (i) + 1), l, (l + r) / 2) +
         segQuery(a, b, (2 * (i) + 2), (l + r) / 2 + 1, r);
}
void segUpdate(int i) {
  seg[i] = seg[(2 * (i) + 1)] + seg[(2 * (i) + 2)];
  if (i > 0) segUpdate((((i)-1) / 2));
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
void frac(long long &a, long long &b) {
  long long g = gcd(abs(a), abs(b));
  a = a / g;
  b = b / g;
}
int n, qq;
int k[100000];
map<pair<long long, long long>, int> last;
deque<pair<int, int>> e;
pair<pair<int, int>, int> q[100000];
int res[100000];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
    vector<pair<long long, long long>> w;
    for (int j = 0; j < k[i]; ++j) {
      long long x, y;
      cin >> x >> y;
      w.push_back({x, y});
    }
    w.push_back(w[0]);
    for (int j = 0; j < k[i]; ++j) {
      long long dx = w[j + 1].first - w[j].first,
                dy = w[j + 1].second - w[j].second;
      frac(dx, dy);
      if (last.count({dx, dy}))
        e.push_back({last[{dx, dy}] + 1, i});
      else
        e.push_back({0, i});
      last[{dx, dy}] = i;
    }
  }
  sort(e.begin(), e.end());
  cin >> qq;
  for (int i = 0; i < qq; ++i) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    q[i] = {{l, r}, i};
  }
  sort(q, q + qq);
  int cur = 0;
  for (int i = 0; i < qq; ++i) {
    while (e.size() > 0 && e.front().first == q[i].first.first) {
      seg[segOff + e.front().second]++;
      segUpdate((((segOff + e.front().second) - 1) / 2));
      e.pop_front();
    }
    res[q[i].second] = segQuery(q[i].first.first, q[i].first.second);
  }
  for (int i = 0; i < qq; ++i) cout << res[i] << "\n";
}

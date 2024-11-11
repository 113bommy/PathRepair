#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int INF = 1e9 + 5;
const double PI = acos(-1);
const int X[] = {1, -1, 0, 0};
const int Y[] = {0, 0, 1, -1};
const int mod = 1e9 + 7;
int q;
long long n, p[N], a, b, x, y, k, newp[N], c[N];
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first > b.first;
}
bool f(int d) {
  vector<pair<int, int>> v;
  for (int i = 1; i <= d; i++) {
    v.push_back({c[i], i});
  }
  sort(v.begin(), v.end(), &cmp);
  int j = n;
  for (int i = 0; i < v.size(); i++) {
    newp[v[i].second] = p[j];
    j--;
  }
  long long ans = 0;
  for (int i = 1; i <= d; i++) {
    ans += newp[i] * c[i] / 100;
    if (ans >= k) {
      return 1;
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      newp[i] = c[i] = 0;
    }
    cin >> x >> a;
    cin >> y >> b;
    cin >> k;
    for (int i = a; i <= n; i += a) {
      c[i] += x;
    }
    for (int i = b; i <= n; i += b) {
      c[i] += y;
    }
    sort(p + 1, p + n + 1);
    int l = 1, r = n;
    for (int i = 1; i <= 18; i++) {
      int md = (l + r) / 2;
      if (f(md)) {
        r = md;
      } else {
        l = md;
      }
    }
    if (f(r)) {
      cout << r << "\n";
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}

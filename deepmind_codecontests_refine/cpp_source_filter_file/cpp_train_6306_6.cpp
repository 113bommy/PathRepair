#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int maxf = 10005;
int n, k;
int fen[100005];
int f[100005];
struct rad {
  int x, r;
  rad() {}
} a[maxn];
vector<int> freq[maxf];
void add(int i, int val) {
  while (i <= maxn) {
    fen[i] += val;
    i += i & -i;
  }
}
int get(int i) {
  int ret = 0;
  while (i > 0) {
    ret += fen[i];
    i -= i & -i;
  }
  return ret;
}
long long go(int cur) {
  long long ret = 0;
  vector<int> p;
  for (int i = max(0, cur - k); i <= min(maxf - 1, cur + k); i++) {
    for (const auto &j : freq[i]) p.push_back(j);
  }
  sort(p.begin(), p.end(), [&](int i, int j) { return a[i].x < a[j].x; });
  vector<int> q;
  for (int i = 0; i < p.size(); i++) q.push_back(i);
  sort(q.begin(), q.end(), [&](int i, int j) {
    return a[p[i]].x + a[p[i]].r < a[p[j]].x + a[p[j]].r;
  });
  memset(fen, 0, sizeof(int) * ((int)(p.size())));
  for (int i = 0, j = 0; i < (int)p.size(); i++)
    if (f[p[i]] == cur) {
      while (a[p[q[j]]].x + a[p[q[j]]].r < a[p[i]].x) add(q[j++] + 1, 1);
      int xr = a[p[i]].x - a[p[i]].r;
      int low = 0, high = i - 1, mid;
      while (low < high) {
        mid = (low + high) >> 1;
        if (a[p[mid]].x < xr)
          low = mid + 1;
        else
          high = mid;
      }
      ret += (i - low) - (get(i + 1) - get(low));
    }
  return ret;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x, r;
    cin >> x >> r >> f[i];
    a[i].x = x;
    a[i].r = r;
    freq[f[i]].push_back(i);
  }
  long long ans = 0;
  for (int i = 0; i < maxf; i++)
    if (!freq[i].empty()) ans += go(i);
  cout << ans << endl;
  return 0;
}

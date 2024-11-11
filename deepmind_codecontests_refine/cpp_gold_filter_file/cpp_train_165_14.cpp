#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 17, lg = 18, lgv = 30, inf = 2e9;
int n, cer[lgv], mx[lg][maxn], lg2[maxn];
multiset<int> s;
int get(int l, int r) {
  if (l < 0) l = 0;
  if (r <= l) return inf;
  int k = lg2[r - l];
  return max(mx[k][l], mx[k][r - (1 << k)]);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  memset(cer, -1, sizeof cer);
  for (int i = 0; i <= lgv; i++) s.insert(-1);
  for (int i = 2; i < maxn; i++) lg2[i] = lg2[i / 2] + 1;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> mx[0][i];
  int *a = mx[0];
  for (int k = 1; k < lg; k++)
    for (int i = 0; i + (1 << k) <= n; i++)
      mx[k][i] = max(mx[k - 1][i], mx[k - 1][i + (1 << k - 1)]);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < lgv; j++)
      if (a[i] >> j & 1) {
        s.erase(s.find(cer[j]));
        s.insert(cer[j] = i);
      }
    int cur = 0;
    for (auto it = --s.end(); *it != -1; it--) {
      cur |= a[*it];
      int lo = *prev(it), hi = *it + 1;
      while (hi - lo > 1) {
        int mid = lo + hi >> 1;
        (get(mid, i + 1) >= cur ? lo : hi) = mid;
      }
      ans += *it - lo;
    }
  }
  cout << ans << '\n';
}

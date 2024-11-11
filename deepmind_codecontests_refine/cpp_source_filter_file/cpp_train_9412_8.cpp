#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 * 1000 + 20, maxm = 2 * 10 + 2;
int n, m, d, ans = maxm, choosenA[maxm], Aind[maxn];
bool badset[1 << maxm];
int main() {
  cin >> n >> m >> d;
  for (int i = 0, a, si; i < m; i++) {
    cin >> si;
    while (si--) cin >> a, Aind[a] = i;
  }
  for (int i = 1; i <= d; i++) choosenA[Aind[i]]++;
  for (int i = d + 1, mask; i <= n; i++, mask = 0) {
    for (int j = 0; j < m; j++)
      if (!choosenA[j]) {
        mask |= (1 << j);
      }
    badset[mask] = 1;
    choosenA[Aind[i]]++;
    choosenA[Aind[i - d]]--;
  }
  int tmp = 0;
  for (int i = 1; i <= m; i++)
    if (!choosenA[i]) tmp |= (1 << i);
  badset[tmp] = 1;
  for (int mask = (1 << m) - 1; mask > 0; mask--) {
    for (int i = 0; i < m; i++) badset[mask] |= badset[mask | (1 << i)];
    if (!badset[mask]) {
      ans = min(ans, __builtin_popcount(mask));
    }
  }
  cout << ans << endl;
  return 0;
}

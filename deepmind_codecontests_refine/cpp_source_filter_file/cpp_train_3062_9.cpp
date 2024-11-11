#include <bits/stdc++.h>
using namespace std;
const int maxl = 1005;
const int maxn = 100005;
int n, k, maxh, s[maxl], f[maxn];
vector<int> p[maxn];
int main() {
  scanf("%d%d", &n, &k), maxh = sqrt(6 * n) + 1;
  for (int x, y, i = 1; i <= k; i++) {
    scanf("%d%d", &x, &y);
    p[y + (n - x)].push_back(min(maxh, n - x));
  }
  for (int i = 1; i <= n; i++) {
    memset(s, 0, maxh * 4);
    for (int j = 0; j < p[i].size(); j++) s[p[i][j]]++;
    for (int j = maxh; j >= 0; j--) s[j] += s[j + 1];
    int ans_cur = f[0] + s[0] * 3;
    for (int j = min(i, maxh); j > 0; j--) {
      ans_cur = min(ans_cur, f[j - 1] + s[j] * 3 + j * (j + 1) / 2 + 2);
      f[j] = f[j - 1] + s[j] * 3;
    }
    f[0] = ans_cur;
    for (int j = 1; j <= min(i, maxh); j++) f[j] = min(f[j], f[j - 1]);
  }
  printf("%d", f[0]);
  return 0;
}

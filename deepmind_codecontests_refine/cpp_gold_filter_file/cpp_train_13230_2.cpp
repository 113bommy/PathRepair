#include <bits/stdc++.h>
using namespace std;
vector<char> ans;
int n, x, num[500005], use[500005], sum[500005][1 << 6];
char s[500005], ss[500005];
int main() {
  scanf("%s", s + 1);
  scanf("%d", &n);
  int m = strlen(s + 1);
  for (int i = 1; i <= m; i++) num[s[i] - 'a']++;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    scanf("%s", ss + 1);
    int tmp = 0;
    for (int j = 1; j <= strlen(ss + 1); j++) tmp |= (1 << (ss[j] - 'a'));
    use[x] = tmp;
  }
  int all = 1 << 6;
  all--;
  n = m;
  for (int i = 1; i <= n; i++)
    if (!use[i]) use[i] = all;
  for (int i = n; i; i--) {
    for (int j = all; j; j--) sum[i][j] = sum[i + 1][j];
    for (int j = all; j; j--)
      if ((j & use[i]) == use[i]) sum[i][j]++;
  }
  for (int i = 1; i <= n; i++) {
    bool flag1 = 0;
    for (int j = 0; j < 6; j++) {
      int flag2 = 1;
      if (!num[j] || (use[i] & (1 << j)) == 0) continue;
      num[j]--;
      for (int k = 1; k <= all; k++) {
        int summ = 0;
        for (int p = 0; p < 6; p++)
          if (k >> p & 1) summ += num[p];
        if (summ < sum[i + 1][k]) {
          flag2 = 0;
          break;
        }
      }
      if (flag2) {
        flag1 = 1;
        ans.push_back('a' + j);
        break;
      }
      num[j]++;
    }
    if (!flag1) return puts("Impossible"), 0;
  }
  for (int i = 0; i < (int)ans.size(); i++) putchar(ans[i]);
  return 0;
}

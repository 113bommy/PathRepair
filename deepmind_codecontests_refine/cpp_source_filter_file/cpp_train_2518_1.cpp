#include <bits/stdc++.h>
using namespace std;
int T, n, cnt1[4], cnt2[4], st[4010], to;
char s[4010], t[4010];
void work(int x) {
  if (x == 0) return;
  st[++to] = x;
  reverse(s + 1, s + x + 1);
}
void solve() {
  to = 0;
  scanf("%s%s", s + 1, t + 1), n = strlen(s + 1);
  for (int i = 1; i <= n; i++) s[i] &= 1, t[i] &= 1;
  for (int i = 0; i < 4; i++) cnt1[i] = cnt2[i] = 0;
  for (int i = 2; i <= n; i += 2)
    cnt1[s[i - 1] << 1 | s[i]]++, cnt2[t[i - 1] << 1 | t[i]]++;
  if (cnt1[0] != cnt2[0] || cnt1[3] != cnt2[3]) return puts("-1"), void();
  int t1 = cnt1[1] - cnt2[2], t2 = cnt2[1] - cnt1[2], falg = 0;
  if (abs(t1) < abs(t2)) swap(s, t), falg ^= 1;
  if (t1 != -t2)
    for (int i = 2, tmp = 0; i <= n; i += 2) {
      if ((s[i - 1] << 1 | s[i]) == 1) tmp++;
      if ((s[i - 1] << 1 | s[i]) == 2) tmp--;
      if (t1 - 2 * tmp == -t2) {
        work(i);
        break;
      }
    }
  for (int i = 2; i <= n; i += 2) {
    for (int j = i; j <= n; j += 2) {
      if (s[j] == t[n - i + 1] && s[j - 1] == t[n - i + 2]) {
        work(j - 2), work(j);
        break;
      }
    }
  }
  if (falg) reverse(st + 1, st + to + 1);
  printf("%d\n", to);
  for (int i = 1; i <= to; i++) printf("%d ", st[i]);
  puts("");
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
}

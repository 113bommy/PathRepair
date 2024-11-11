#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[100000 + 1109];
char s[100000 + 1109], a[100000 + 1109];
int slen, alen;
int DP[100000 + 1109];
int Cnt[100000 + 1109];
int Pre[100000 + 1109];
bool b[100000 + 1109];
int main() {
  scanf("%d%s%d", &n, s, &m);
  int now = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 1) {
      if (s[i] == 'a' || s[i] == '?')
        now++;
      else
        now = 0;
    } else {
      if ((s[i] == 'b' || s[i] == '?') && now != 0)
        now++;
      else
        now = 0;
    }
    if (now >= m && (now - m) % 2 == 0) b[i + 1] = true;
  }
  now = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (s[i] == 'a' || s[i] == '?')
        now++;
      else
        now = 0;
    } else {
      if ((s[i] == 'b' || s[i] == '?') && now != 0)
        now++;
      else
        now = 0;
    }
    if (now >= m && (now - m) % 2 == 0) b[i + 1] = true;
  }
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '?')
      Pre[i] = Pre[i - 1] + 1;
    else
      Pre[i] = Pre[i - 1];
    if (i >= m)
      if (Pre[i] - Pre[i - m] == m) b[i] = true;
  }
  for (int i = 1; i <= n; i++) {
    DP[i] = DP[i - 1];
    Cnt[i] = Cnt[i - 1];
    if (b[i]) {
      if (DP[i - m] + 1 > DP[i]) {
        DP[i] = DP[i - m] + 1;
        Cnt[i] = Cnt[i - m] + Pre[i] - Pre[i - m];
      } else if (DP[i - m] + 1 == DP[i]) {
        Cnt[i] = min(Cnt[i - m] + Pre[i] - Pre[i - m], Cnt[i]);
      }
    }
  }
  printf("%d", Cnt[n]);
  return 0;
}

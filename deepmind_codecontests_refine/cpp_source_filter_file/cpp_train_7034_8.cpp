#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
int a[300105], b[300105], L;
char S[300105];
long long s[300105];
int md[300105], dp[2][300105 * 20], mx[300105 * 20];
void cal(int mod, int &ans) {
  long long tmp = 0;
  for (int j = L; j; j--) {
    tmp = tmp * (1000000000) + s[j];
    s[j] = tmp / mod;
    tmp %= mod;
  }
  ans = tmp;
  while (L > 1 && s[L] == 0) L--;
}
void addp(int t, int x, int v) {
  addmod(dp[t][x], v);
  mx[t] = max(mx[t], x);
}
void fmain(int tid) {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) scanf("%d", a + i);
  a[n + 1] = (1000000000);
  a[1] = 1;
  for (int(i) = 1; (i) <= (int)(n); (i)++) scanf("%d", b + i);
  scanf("%s", S + 1);
  m = strlen(S + 1);
  reverse(S + 1, S + 1 + m);
  L = m / 9 + (m % 9 != 0);
  for (int(i) = 1; (i) <= (int)(L); (i)++) {
    for (int j = min(i * 9, m); j > (i - 1) * 9; j--) {
      s[i] = s[i] * 10 + (S[j] - '0');
    }
  }
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    if (a[i + 1] != 1) {
      cal(a[i + 1], md[i]);
    }
  if (L != 1 && s[L] != 0) {
    puts("0");
    return;
  }
  int t = 0;
  dp[0][0] = 1;
  dp[0][1] = 1000000007 - 1;
  mx[0] = 1;
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    int pre = t, cur = t ^ 1;
    t ^= 1;
    for (int(j) = 1; (j) <= (int)(mx[pre]); (j)++) {
      addmod(dp[pre][j], dp[pre][j - 1]);
    }
    for (int j = 0; j <= mx[pre]; j++)
      if (dp[pre][j] != 0) {
        int k = (md[i] - j % a[i + 1] + a[i + 1]) % a[i + 1];
        int l = (j + k - md[i]) / a[i + 1];
        if (b[i] >= k) {
          int r = (b[i] - k) / a[i + 1] + l;
          addp(cur, l, dp[pre][j]);
          addp(cur, r + 1, 1000000007 - dp[pre][j]);
        }
        dp[pre][j] = 0;
      }
    mx[pre] = 0;
  }
  printf("%d\n", dp[t][0]);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}

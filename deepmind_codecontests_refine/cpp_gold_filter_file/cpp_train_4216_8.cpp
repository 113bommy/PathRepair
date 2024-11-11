#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-8;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
long long q1[N], q2[N], sum1[N], sum2[N];
int C(long long x) { return (x % MOD + MOD) % MOD; }
bool check(int i, int l) {
  return (C(q1[i - 1] * sum1[l]) == C(sum1[i + l - 1] - sum1[i - 1])) &&
         (C(q2[i - 1] * sum2[l]) == C(sum2[i + l - 1] - sum2[i - 1]));
}
int n, m;
bool v[N];
char s[N];
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  int p = strlen(s + 1);
  q1[0] = q2[0] = 1;
  for (int i = 1; i <= p; i++) {
    sum1[i] = (sum1[i - 1] + s[i] * q1[i - 1]) % MOD;
    sum2[i] = (sum2[i - 1] + s[i] * q2[i - 1]) % MOD;
    q1[i] = q1[i - 1] * 71 % MOD, q2[i] = q2[i - 1] * 43 % MOD;
  }
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    v[x] = 1;
  }
  int last = -INF;
  for (int i = 1; i <= n; i++)
    if (v[i]) {
      if (last != -INF) {
        if ((last + p > i) && !check(i - last + 1, p - (i - last))) {
          puts("0");
          return 0;
        }
      }
      last = i;
    } else if (last + p > i)
      v[i] = 1;
  int ans = 1;
  for (int i = 1; i <= n; i++)
    if (!v[i]) ans = (long long)ans * 26 % MOD;
  printf("%d\n", ans);
}

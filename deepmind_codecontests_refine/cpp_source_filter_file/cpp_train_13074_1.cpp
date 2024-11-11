#include <bits/stdc++.h>
using namespace std;
int n, m, s, cnt, ans, last;
int dp[10005], d[10005], v[10005], q[20], pre[10005];
int V[200005], phi[200005];
bool b[200005];
int p[10], c[10], jc[10];
inline int pow(int x, int k, int mo) {
  int ans = 1;
  for (; k; k >>= 1, x = 1LL * x * x % mo)
    if (k & 1) ans = 1LL * ans * x % mo;
  return ans;
}
inline int gcd(int x, int y) { return x == 0 ? y : gcd(y % x, x); }
inline int read() {
  int ret = 0;
  char c = getchar();
  while ((c > '9') || (c < '0')) c = getchar();
  while ((c >= '0') && (c <= '9'))
    ret = (ret << 1) + (ret << 3) + c - '0', c = getchar();
  return ret;
}
void Pre() {
  int tmp = m;
  for (int i = 2; i * i <= tmp; i++)
    if (tmp % i == 0) {
      while (tmp % i == 0) tmp /= i, c[cnt]++;
      p[cnt++] = i;
    }
  if (tmp > 1) c[cnt] = 1, p[cnt++] = tmp;
  s = 1;
  d[0] = 1;
  jc[0] = 1;
  phi[1] = 1;
  for (int i = 0; i < cnt; i++) {
    for (int j = 1; j <= c[i]; j++)
      for (int k = 0; k < s; k++) {
        d[k + j * s] = d[k + (j - 1) * s] * p[i];
        if (j == 1)
          phi[d[k + j * s]] = phi[d[k + (j - 1) * s]] * (p[i] - 1);
        else
          phi[d[k + j * s]] = phi[d[k + (j - 1) * s]] * p[i];
      }
    s *= c[i] + 1;
    jc[i + 1] = s;
  }
  for (int i = 0; i < m; i++)
    if (!b[i]) V[gcd(i, m)]++;
  for (int i = 0; i < s; i++) v[i] = V[d[i]];
}
inline int f(int x) {
  if (x == 0) return 0;
  int re = 1, g1 = gcd(last, m), g2 = gcd(x, m);
  if (g2 > g1) re = g2 / g1, last = last * g2 / g1 % m;
  x /= g2, last /= g2;
  return 1LL * re * x * pow(last, phi[m / g2] - 1, m / g2) % m;
}
void work() {
  for (int i = 0; i < s; i++) pre[i] = -1, dp[i] = v[i];
  for (int i = 0; i < s; i++)
    for (int j = 0; j < i; j++)
      if ((d[i] % d[j] == 0) && (dp[j] + v[i] > dp[i]))
        dp[i] = dp[j] + v[i], pre[i] = j;
  q[++ans] = s - 1;
  while (v[q[1]] == 0) q[1] = pre[q[1]];
  while (pre[q[ans]] != -1) q[ans + 1] = pre[q[ans]], ans++;
  printf("%d\n", dp[q[1]]);
  last = 1;
  for (int i = ans; i; i--)
    for (int j = 0; j < m; j++)
      if (gcd(j, m) == d[q[i]])
        if (!b[j]) {
          printf("%d ", f(j));
          last = j;
        }
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) b[read()] = true;
  Pre();
  work();
}

#include <bits/stdc++.h>
using namespace std;
const int N = 210005, M = 2000005, p = 1000000007;
int read() {
  int f = 1, g = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) g = g * 10 + ch - '0';
  return f * g;
}
int qpow(int x, int k) {
  int t = 1;
  for (; k; k >>= 1) {
    if (k & 1) t = (long long)t * x % p;
    x = (long long)x * x % p;
  }
  return t;
}
int n, a[N], pr[M], f[M], b[M], cnt[M], ans, fl;
void add(int t, int k) {
  if (b[t] < k) {
    b[t] = k;
    cnt[t] = 1;
  } else if (b[t] == k)
    cnt[t]++;
}
bool check(int t, int k) { return (b[t] < k) || (cnt[t] > 1); }
void calc(int x) {
  while (x > 1) {
    int t = 0, k = f[x];
    while (f[x] == k) {
      t++;
      x /= k;
    }
    add(k, t);
  }
}
bool res(int x) {
  while (x > 1) {
    int t = 0, k = f[x];
    while (f[x] == k) {
      t++;
      x /= k;
    }
    if (!check(k, t)) return false;
  }
  return true;
}
int main() {
  for (int i = 2; i < M; i++) {
    if (!f[i]) {
      f[i] = pr[++pr[0]] = i;
    }
    for (int j = 1; (j <= pr[0]) && (pr[j] <= f[i]) && (i * pr[j] < M); j++)
      f[i * pr[j]] = pr[j];
  }
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + n + 1);
  for (int i = n; i; i--)
    if (b[a[i]]) {
      a[i]--;
      calc(a[i]);
    } else
      add(a[i], 1);
  for (int i = 1; i <= n; i++)
    if (res(a[i])) fl = 1;
  ans = 1;
  for (int i = 2; i < M; i++)
    if (b[i]) ans = (long long)ans * qpow(i, b[i]) % p;
  printf("%d\n", (ans + fl) % p);
  return 0;
}

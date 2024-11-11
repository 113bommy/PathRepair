#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int i, j, n, k, mo, rev[N], a[N], num, d[N], s[N], l, r;
long long ans;
void work(int l, int r, int k) {
  if (k <= 1 || l == r) {
    a[++num] = r - l + 1;
    return;
  }
  int m = (l + r) >> 1;
  work(l, m, k - 1), work(m + 1, r, k - 1);
}
int calc(int a, int b) {
  int i;
  long long S = (long long)a * b % mo;
  for (i = 1; i <= a; i++) S -= s[i + b] - s[i];
  return S;
}
int main() {
  scanf("%d%d%d", &n, &k, &mo);
  rev[0] = rev[1] = 1;
  for (i = 2; i <= n; i++) rev[i] = (long long)(mo - mo / i) * rev[mo % i] % mo;
  for (i = 1; i <= n; i++) s[i] = (s[i - 1] + rev[i]) % mo;
  for (i = 1; i <= n; i++) s[i] <<= 1;
  work(1, n, k);
  for (i = 1; i <= num; i++) d[a[i]]++;
  for (i = 1; i <= n; i++)
    if (d[i]) l = !l ? i : l, r = i;
  for (i = l; i <= r; i++)
    ans += ((long long)i * (i - 1) / 2 % mo * d[i] +
            (long long)d[i] * (d[i] - 1) / 2 % mo * calc(i, i)) %
           mo;
  if (l != r) ans += (long long)d[l] * d[r] % mo * calc(l, r) % mo;
  ans = ans % mo * (mo + 1) / 2 % mo;
  printf("%lld\n", (ans + mo) % mo);
}

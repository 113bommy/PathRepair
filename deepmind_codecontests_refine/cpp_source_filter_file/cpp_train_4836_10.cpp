#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
const int M = 1000100;
const int P = 1000000007;
int fac[M], phi[M];
vector<int> prime;
long long val[M], sum[M], res[M];
long long ans[M], vec[M], rec[M];
void init_() {
  fac[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (!fac[i]) {
      fac[i] = i;
      prime.push_back(i);
    }
    for (int j = 0; j <= (int)prime.size() - 1; j++) {
      int p = prime[j];
      if (p * i > N) break;
      fac[p * i] = p;
      if (fac[i] == p) break;
    }
  }
  phi[1] = 1;
  for (int i = 2; i <= N; i++) {
    int p = fac[i];
    int j = i / p;
    int p_ = fac[j];
    if (p == p_)
      phi[i] = phi[j] * p;
    else
      phi[i] = phi[j] * (p - 1);
  }
  for (int i = 1; i <= N; i++) val[i] = (val[i - 1] + i) % P;
  for (int i = 1; i <= N; i++) sum[i] = (sum[i - 1] + (long long)i * i) % P;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N / i; j++) (res[i * j] += (long long)i * phi[j]) %= P;
  for (int i = 1; i <= N; i++)
    ans[i] =
        (sum[i] + sum[i - 1] + 2 * (2 * P - val[i] - val[i - 1] + res[i])) % P;
  for (int i = 1; i <= N; i++) vec[i] = (vec[i - 1] + ans[i] * i) % P;
  for (int i = 1; i <= N; i++) rec[i] = (rec[i - 1] + ans[i] * i % P * i) % P;
  for (int i = 1; i <= N; i++) ans[i] = (ans[i - 1] + ans[i]) % P;
}
int main() {
  init_();
  int _;
  cin >> _;
  while (_--) {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n > m) swap(n, m);
    n++, m++;
    int o = (ans[n] * n % P * m % P - (n + m) * vec[n] % P + rec[n] + P) % P;
    printf("%d\n", o);
  }
  return 0;
}

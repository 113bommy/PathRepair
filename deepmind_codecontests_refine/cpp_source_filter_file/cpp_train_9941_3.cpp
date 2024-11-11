#include <bits/stdc++.h>
using namespace std;
const int N = 3004;
const int mod = 1000000007;
int A[N];
long long int F[N], IF[N];
long long int _pow(long long int a, long long int b) {
  if (!b) return 1;
  if (b == 1) return a;
  if (b == 2) return a * a % mod;
  if (b & 1) {
    return a * _pow(a, b - 1) % mod;
  }
  return _pow(_pow(a, b / 2), 2);
}
void pre() {
  F[0] = 1;
  for (int i = 1; i < N; i++) {
    F[i] = F[i - 1] * i % mod;
  }
  IF[N - 1] = _pow(F[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) {
    IF[i] = IF[i + 1] * (i + 1) % mod;
  }
}
long long int nCr(int n, int r) {
  if (r > n) return 0;
  long long int res = F[n] * IF[n - r] % mod;
  return res * IF[r] % mod;
}
int main() {
  int k;
  scanf("%d", &k);
  pre();
  long long int ans = 1;
  int cnt = 1;
  for (int i = 1; i < k + 1; i++) {
    int x;
    scanf("%d", &x);
    ans = ans * nCr(cnt + x - 2, cnt - 1);
    cnt += x;
  }
  cout << ans << "\n";
  return 0;
}

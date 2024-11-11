#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
long long int fat[N], fat_inv[N];
long long int mul_inv(long long int a) {
  long long int pin0 = MOD, pin = MOD, t, q;
  long long int x0 = 0, x1 = 1;
  if (pin == 1) return 1;
  while (a > 1) {
    q = a / pin;
    t = pin, pin = a % pin, a = t;
    t = x0, x0 = x1 - q * x0, x1 = t;
  }
  if (x1 < 0) x1 += pin0;
  return x1;
}
vector<long long int> v;
long long int comp(long long int n, long long int k) {
  long long int ret = 0;
  ret = (fat[n] * fat_inv[k]) % MOD;
  ret = (ret * fat_inv[n - k]) % MOD;
  return ret;
}
long long int r = 0;
int n;
void resp_0() {
  for (int i = 0; i < n; i++) {
    if (i % 2) {
      r = (r - comp((n - 1) / 2, i / 2) * v[i]) % MOD;
    } else {
      r = (r + comp((n - 1) / 2, i / 2) * v[i]) % MOD;
    }
  }
}
void resp_1() {
  for (int i = 0; i < n; i++) {
    if (i % 2) {
      continue;
    } else {
      r = (r + comp(n / 2, i / 2) * v[i]) % MOD;
    }
  }
}
void resp_2() {
  for (int i = 0; i < n; i++) {
    if (i % 2) {
      r = (r + comp((n - 1) / 2, i / 2) * v[i]) % MOD;
    } else {
      r = (r + comp((n - 1) / 2, i / 2) * v[i]) % MOD;
    }
  }
}
int main() {
  fat[0] = 1;
  for (long long int i = 1; i < N; i++) fat[i] = (fat[i - 1] * i) % MOD;
  for (int i = 0; i < N; i++) fat_inv[i] = mul_inv(fat[i]);
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  if (n % 4 == 0)
    resp_0();
  else if (n % 4 == 1)
    resp_1();
  else if (n % 4 == 2)
    resp_2();
  else {
    for (int i = 0; i < n - 1; i++)
      if (i % 2)
        v[i] += v[i + 1];
      else
        v[i] -= v[i + 1];
    n--;
    resp_2();
  }
  r += MOD;
  r %= MOD;
  cout << r << endl;
  return 0;
}

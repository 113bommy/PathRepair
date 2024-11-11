#include <bits/stdc++.h>
using namespace std;
long long fact[1000000 + 1];
long long inv_fact[1000000 + 1];
long long nci[1000000 + 1];
long long modul = 998244353;
long long powermod(long long a, long long n) {
  if (a == 0) {
    return 0;
  }
  if (a == 1 or n == 0) {
    return 1;
  }
  if (a < 0) {
    if (n % 2) {
      return (modul - powermod(-a, n)) % modul;
    } else {
      return powermod(-a, n);
    }
  }
  if (n == 1) {
    return a % modul;
  }
  long long halfpower = powermod(a, n / 2);
  if (n % 2) {
    return (((a * halfpower) % modul) * halfpower) % modul;
  } else {
    return (halfpower * halfpower) % modul;
  }
}
long long nCr(long long n, long long r) {
  return (((fact[n] * inv_fact[r]) % modul) * inv_fact[n - r]) % modul;
}
int main() {
  long long n;
  cin >> n;
  fact[0] = 1;
  fact[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fact[i] = (fact[i - 1] * i) % modul;
  }
  for (int i = 0; i <= n; ++i) {
    inv_fact[i] = powermod(fact[i], modul - 2);
  }
  nci[0] = 1;
  for (int i = 1; i <= (n + 1) / 2; ++i) {
    nci[i] = (((fact[n] * inv_fact[i]) % modul) * inv_fact[n - i]) % modul;
  }
  for (int i = (n + 1) / 2; i <= n; ++i) {
    nci[i] = nci[n - i];
  }
  long long ans1 =
      (2 * (powermod(3, n * n) -
            powermod((modul + powermod(3, n) - 3) % modul, n) + modul)) %
      modul;
  long long ans2 = 0;
  for (int i = 1; i <= n; ++i) {
    ans2 += (((nci[i] * powermod(-1, i)) % modul) *
             (powermod((powermod(3, n - i) - 1), n) + modul -
              powermod(3, n * (n - i))) %
             modul) %
            modul;
    ans2 = ans2 % modul;
  }
  cout << (3 * modul + ans1 - (3 * ans2)) % modul << "\n";
}

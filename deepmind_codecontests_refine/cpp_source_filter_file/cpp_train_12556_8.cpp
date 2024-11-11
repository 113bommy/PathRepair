#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using namespace std::chrono;
int n;
int const N = (1 << 20);
char a[N];
int sum_of_dig[N];
ll const P = 1e9 + 7;
vector<ll> f;
vector<ll> jej;
vector<ll> fft(const vector<ll>& inp) {
  if (inp.size() == 1) return inp;
  vector<ll> pom1;
  vector<ll> pom2;
  int k = (int)(inp.size()) / 2;
  for (int i = (0); i <= (k - 1); i++) {
    pom1.push_back(((inp[i] + inp[k + i]) * ((P + 1) / 2)) % P);
    pom2.push_back(((inp[i] - inp[k + i] + P) * ((P + 1) / 2)) % P);
  }
  pom1 = fft(pom1);
  pom2 = fft(pom2);
  for (int i = (0); i <= (k - 1); i++) pom1.push_back(pom2[i]);
  return pom1;
}
ll power(ll a, ll pow) {
  if (!pow) return 1;
  ll x = power(a, pow / 2);
  if (pow % 2)
    return (a * ((x * x) % P)) % P;
  else
    return (x * x) % P;
}
int main() {
  scanf("%d", &n);
  scanf("%s", &a);
  for (int i = (0); i <= ((1 << n) - 1); i++)
    f.push_back((a[i] == '1') ? 1 : 0);
  jej = fft(f);
  ll ans = 0;
  sum_of_dig[0] = 0;
  for (int i = (0); i <= ((1 << n) - 1); i++) {
    sum_of_dig[i] = (i % 2) ? sum_of_dig[i / 2] + 1 : sum_of_dig[i / 2];
    ans =
        (ans + (power(3, n - sum_of_dig[i]) * ((jej[i] * jej[i]) % P)) % P) % P;
  }
  ans = (ans * (3 * power(2, n)) % P) % P;
  printf("%I64d ", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool isPrime[1000005] = {false};
vector<long long int> SPF(1000005);
long long int fastPower(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int prod = 1;
  while (b > 0) {
    if (b & 1) prod = prod * a;
    b = b >> 1;
    a = a * a;
  }
  return prod;
}
void sieve() {
  int i;
  for (i = 2; i < 1000005; ++i) isPrime[i] = 1;
  for (i = 2; i * i < 1000005; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j < 1000005; j += i) isPrime[j] = 0;
    }
  }
}
void printa(bool f) {
  if (f)
    cout << "YES";
  else
    cout << "NO";
  cout << "\n";
}
bool flip(bool f) {
  if (f) return 0;
  return 1;
}
void solve() {
  long long int i, n;
  cin >> n;
  int m = (n / 2 + 1);
  cout << m << "\n";
  for (int i = 1; i <= m && n--; ++i) cout << 1 << ' ' << i << "\n";
  for (int i = 2; i <= m && n--; ++i) cout << i << ' ' << m << "\n";
}
int main() {
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}

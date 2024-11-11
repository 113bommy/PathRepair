#include <bits/stdc++.h>
using namespace std;
const int N = 32000;
bool isp[N];
vector<int> primes;
int n, i;
void sieve() {
  for (int i = 2; i < N; i++) isp[i] = true;
  for (int i = 4; i < N; i += 2) isp[i] = false;
  for (int i = 3; i * i < N; i += 2)
    if (isp[i])
      for (int j = i + i; j < N; j += i) isp[j] = false;
  for (int i = 2; i < N; i++)
    if (isp[i]) primes.push_back(i);
}
int main() {
  sieve();
  cin >> n;
  long long ans = n;
  for (auto p : primes) {
    while (n % p == 0) {
      n /= p;
      ans += n;
    }
  }
  if (n > 1) ans += n;
  cout << ans << endl;
}

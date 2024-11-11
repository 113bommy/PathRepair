#include <bits/stdc++.h>
using namespace std;
inline void JadedBeast() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const long long MAX = 3e3 + 1;
int primes[MAX];
void sieve() {
  memset(primes, 0, sizeof(primes));
  primes[0] = -1, primes[1] = -1;
  for (int i = 2; i * i < MAX; i++)
    if (!primes[i])
      for (int j = 2; j * i < MAX; j++) primes[i * j]++;
}
int main(void) {
  JadedBeast();
  sieve();
  int n, counter = 0;
  cin >> n;
  for (int i = 3; i <= n; i++)
    if (primes[i] == 2) counter++;
  cout << counter;
}

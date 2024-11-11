#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e7 + 5;
bool P[MAX];
vector<int> Primes;
void Sieve() {
  P[0] = P[1] = true;
  for (int i = 2; i < MAX; i++) {
    if (P[i]) continue;
    Primes.push_back(i);
    for (long long j = 1ll * i * i; j < MAX; j += i) P[j] = true;
  }
}
int main() {
  Sieve();
  int n, i = 0, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cout << Primes[i];
  return 0;
}

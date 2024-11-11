#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
int divi[1000005];
int main() {
  primes.push_back(2);
  for (int i = 4; i <= 1000000; i += 2) divi[i] = 2;
  for (int i = 3; i < 1000000; i += 2) {
    if (divi[i] > 0) continue;
    primes.push_back(i);
    for (int j = i + i; j <= 1000000; j += i) divi[j] = i;
  }
  ios::sync_with_stdio(0);
  int x3;
  cin >> x3;
  int x0 = 1000000;
  for (int pi = 0; pi < (int)primes.size() && primes[pi] < x3; pi++) {
    int p = primes[pi];
    if (x3 % p == 0) {
      for (int i = 0; i < p; i++) {
        if (divi[x3 - i] == 0) continue;
        x0 = min(x0, x3 - i - divi[x3 - i] + 1);
      }
    }
  }
  cout << x0 << '\n';
}

#include <bits/stdc++.h>
using namespace std;
map<char, int> myMap;
int primes[1000005];
void prePrimes() {
  primes[0] = primes[1] = 1;
  for (int i = 2; i < 1000005; i++) {
    if (primes[i] == 0) {
      for (int j = i + i; j < 1000005; j += i) {
        primes[j] = 1;
      }
    }
  }
}
int main() {
  int n, m, flag = 0;
  char x;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x;
      if (x == 'C' || x == 'M' || x == 'Y') flag = 1;
    }
  }
  if (flag)
    cout << "#Color";
  else
    cout << "#Black&White";
}

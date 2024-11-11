#include <bits/stdc++.h>
using namespace std;
long n;
inline bool prime(long p) {
  for (long i = 2; i * i < p; i++) {
    if (p % i == 0) return false;
  }
  return true;
}
int main() {
  cin >> n;
  for (long i = 13; n > 0; i++) {
    if (!prime(i)) continue;
    long p = i, u = 0;
    while (p > 0) {
      u = u * 10 + p % 10;
      p /= 10;
    }
    if (u == i) continue;
    if (prime(u)) {
      n--;
      if (n == 0) {
        cout << i;
        return 0;
      }
    }
  }
}

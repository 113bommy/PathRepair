#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long x) {
  for (long long j = 2; j * j <= x; j++) {
    if (x % j == 0) {
      return false;
    }
  }
  return true;
}
void go(long long& x) {
  for (long long t = x - 2;; t--) {
    if (isPrime(t)) {
      x -= t;
      return;
    }
  }
}
int getAns(long long n) {
  int res = 0;
  while (true) {
    if (isPrime(n)) {
      break;
    }
    res++;
    go(n);
  }
  return res + 1;
}
int main() {
  long long n;
  cin >> n;
  int cand = getAns(n);
  for (int i = 2; i < 13370; i++) {
    if (n - i < 2) {
      break;
    }
    if (isPrime(i)) {
      int curr = getAns(n - i) + 1;
      if (curr < cand) {
        cand = curr;
      }
    }
  }
  cout << cand + 1 << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  long long res;
  long long sub;
  long long prime = 1000000007;
  res = 1;
  for (int c1 = 1; c1 <= n; c1++) {
    res = (res * c1) % prime;
  }
  sub = 1;
  for (int c1 = 0; c1 < n - 1; c1++) {
    sub = (sub * c1) % prime;
  }
  sub = (prime - sub) % prime;
  res = (res + sub) % prime;
  cout << res;
  return 0;
}

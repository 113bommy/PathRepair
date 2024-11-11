#include <bits/stdc++.h>
using namespace std;
bool isprime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
const int M = 2e5 + 5;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long cntl = 0, cntr = 0;
  for (auto c : s) {
    if (c == 'L')
      cntl++;
    else
      cntr++;
  }
  cout << cntr + cntl + 1 << "\n";
}
int main() {
  long long test;
  test = 1;
  while (test--) {
    solve();
  }
  return 0;
}

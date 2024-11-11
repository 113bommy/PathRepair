#include <bits/stdc++.h>
using namespace std;
long long get_next(long long n) {
  int lb = 0;
  while (n != 0) {
    n >>= 1;
    ++lb;
  }
  n = ~n;
  n <<= lb;
  n = ~n;
  return n;
}
long long get_sum(long long n) { return n * (n + 1) / 2; }
int main() {
  int t = 0;
  cin >> t;
  while (t > 0) {
    t--;
    long long n;
    cin >> n;
    cout << get_sum(n) - 2 * get_next(n) << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a, long long b) { return (a > b); }
long long ceil(const long long &a, const long long &b) {
  if (a % b == 0) return a / b;
  return a / b + 1;
}
long long mod = 1000000007;
const long long N = 100005;
long long p, y;
bool check(long long x) {
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return i >= p;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> p >> y;
  while (y > p) {
    if (check(y)) {
      cout << y;
      return 0;
    }
    y--;
  }
  cout << "-1";
  return 0;
}

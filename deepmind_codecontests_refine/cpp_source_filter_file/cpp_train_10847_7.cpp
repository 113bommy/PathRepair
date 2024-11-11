#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
long long f(long long a, long long b) {
  long long ret = 0;
  long long zeroes = 0;
  for (int i = 1; i <= b; i <<= 1) {
    if (b & i) {
      b ^= i;
      if (!(a & b)) ret += 1 << zeroes;
    }
    if (!(a & i)) zeroes++;
  }
  return ret;
}
long long solve(long long a, long long b) {
  if (a == b) return 0;
  if (a == 0) return 2 * (b - 1) + 1 + solve(1, b);
  long long ret = 0;
  if (a & 1) {
    ret = 2 * (f(a, b) - f(a, a));
    a++;
  }
  if (b & 1) {
    ret = 2 * (f(b - 1, b) - f(b - 1, a));
    b--;
  }
  return ret + 3 * solve(a >> 1, b >> 1);
}
int main() {
  int test;
  cin >> test;
  for (int Test = 1; Test <= test; Test++) {
    long long a, b;
    cin >> a >> b;
    cout << solve(a, b + 1) << endl;
  }
  return 0;
}

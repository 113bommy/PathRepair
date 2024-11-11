#include <bits/stdc++.h>
using namespace std;
long long denom = 998244353;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= denom;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % denom;
    a = a * a % denom;
  }
  return res;
}
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(false);
  long long A, B, C, D;
  cin >> A >> B >> C >> D;
  long long result = 0;
  for (long long i = (A); i < (B + 1); i++) {
    long long temp = D + 1 - i;
    if (temp <= B) {
      result += (C - B + 1) * (D - C + 1);
      continue;
    }
    long long d = D;
    long long c = C;
    if (temp > C) {
      d = D - (temp - C);
      if (d < C) continue;
    } else {
      result += (C - temp) * (D - C + 1);
      c = temp;
    }
    long long m1 = c - B + 1;
    long long m2 = d - C + 1;
    long long n = min(m1, m2);
    result += n * (n + 1) / 2;
    if (m2 >= m1) {
      result += m1 * (m2 - m1);
    }
  }
  cout << result;
  return 0;
}

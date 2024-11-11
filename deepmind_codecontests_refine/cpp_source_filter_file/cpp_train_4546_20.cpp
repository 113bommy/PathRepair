#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long n) {
  if (x == 0) return 0;
  long long ret = 1;
  while (n > 0) {
    if (n & 1) ret = (ret * x) % 1000000007;
    x = (x * x) % 1000000007;
    n /= 2;
  }
  return ret;
}
long long ar[300050], n, m;
string second[300050];
int main() {
  long long test, i, j, k, a, b, ans = 0;
  string s1, s2, s3;
  while (test--) {
    cin >> n;
    cout << n / 2 + 1;
  }
  return 0;
}

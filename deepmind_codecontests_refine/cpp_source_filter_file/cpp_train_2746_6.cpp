#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long a[20] = {1,
                   3,
                   15,
                   133,
                   2025,
                   37851,
                   1030367,
                   36362925,
                   1606008513,
                   87656896891,
                   5778121715415,
                   452794797220965,
                   41609568918940625};
long long frac(long long curr) {
  if (curr == 1) return 1;
  return frac(curr - 1) * curr % mod;
}
int main() {
  long long n;
  cin >> n;
  if (n == 0)
    cout << 0 << endl;
  else
    cout << (frac(n) * a[n / 2]) % mod << endl;
}

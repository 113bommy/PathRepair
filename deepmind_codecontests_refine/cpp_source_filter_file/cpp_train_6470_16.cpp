#include <bits/stdc++.h>
using namespace std;
long long add(long long a, long long b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
long long mul(long long a, long long b) {
  return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}
long long binary_expo(long long base, long long expo) {
  long long res = 1;
  while (expo) {
    if (expo % 2) {
      res = mul(res, base);
    }
    expo /= 2;
    base = mul(base, base);
  }
  return res;
}
void solve(long long tc) {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long rem = n - 11;
  long long cnt = 0;
  s = '#' + s;
  long long cnt1 = 0;
  for (long long i = 1; i <= rem; i++) {
    if (s[i] == '8') {
      cnt++;
    } else {
      cnt1++;
    }
  }
  if (cnt >= cnt1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
signed main() {
  long long t, k;
  ios_base::sync_with_stdio(false);
  t = 1;
  long long tc = 1;
  while (t--) {
    solve(tc++);
  }
  return 0;
}

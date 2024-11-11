#include <bits/stdc++.h>
using namespace std;
int INT_MAX_VAL = (int)1e20;
int INT_MIN_VAL = (int)-1e20;
long long LONG_MAX_VAL = (long long)1e20;
long long LONG_MIN_VAL = (long long)-1e20;
long long pow(long long a, long long n) {
  if (n == 1) return a;
  if (n % 2 == 0) {
    long long q = pow(a, n / 2);
    return (q * q) % 1000000007;
  } else {
    long long q = pow(a, n - 1);
    return (q * a) % 1000000007;
  }
}
int cnt[4];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (long long(i) = 0LL; (i) < (n); (i)++) {
    if (s[i] == 'A') {
      cnt[0]++;
    } else if (s[i] == 'C') {
      cnt[1]++;
    } else if (s[i] == 'G') {
      cnt[2]++;
    } else if (s[i] == 'T') {
      cnt[3]++;
    }
  }
  int mx = cnt[0];
  int c = 1;
  for (int i = 1; i < 4; ++i) {
    if (cnt[i] > mx) {
      mx = cnt[i];
      c = 1;
    } else if (cnt[i] == mx) {
      c++;
    }
  }
  cout << pow(c, n) << '\n';
  return 0;
}

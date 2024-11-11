#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long cl(long double a) {
  if (a > (long long)a) {
    return (long long)a + 1;
  } else {
    return (long long)a;
  }
}
long long flr(long double a) { return (long long)a; }
long long n, k;
string s;
void solve() {
  cin >> n >> k >> s;
  string str = s;
  for (long long i = 0; i < n - k; i++) {
    str[i + k] = str[i];
  }
  if (str < s) {
    long long pos = k - 1;
    while (pos > 0 && s[pos] == '9') {
      for (long long i = pos; i < n; i += k) {
        str[pos] = '0';
      }
      pos--;
    }
    char ch = s[pos] + 1;
    for (long long i = pos; i < n; i += k) {
      str[i] = ch;
    }
  }
  cout << n << "\n";
  cout << str << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}

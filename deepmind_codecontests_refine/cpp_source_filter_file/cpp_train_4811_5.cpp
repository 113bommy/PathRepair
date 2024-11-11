#include <bits/stdc++.h>
using namespace std;
long long int power_mod(long long int a, long long int x) {
  if (x == 0) return 1;
  long long int y = power_mod(a, x / 2);
  long long int ans = (y * y) % 1000000007;
  if (x % 2) ans = (ans * a) % 1000000007;
  return ans;
}
long long int inv(long long int a) { return power_mod(a, 1000000007 - 2); }
long long int power(long long int a, long long int x) {
  if (x == 0) return 1;
  long long int y = power(a, x / 2);
  long long int ans = (y * y);
  if (x % 2) ans *= a;
  return ans;
}
int main() {
  long long int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string l(n, '0');
  for (int i = 1; i <= k; i++) {
    for (int j = i; j <= n; j += k) {
      l[j] = s[i];
    }
  }
  if (l >= s) {
    cout << n << endl;
    cout << l << endl;
    return 0;
  }
  int done = -1;
  for (int i = k; i >= 1; i--) {
    if (done == -1) {
      int flag = 1;
      if (s[i - 1] != '9') {
        flag = 0;
      }
      if (flag == 1) {
        for (int j = i; j <= n; j += k) {
          s[j - 1] = s[i - 1];
        }
      } else {
        int x = s[i - 1] - '0';
        for (int j = i; j <= n; j += k) {
          s[j - 1] = (x + 1) + '0';
        }
        done = i;
      }
    } else {
      for (int j = i; j <= n; j += k) {
        s[j - 1] = s[i - 1];
      }
    }
  }
  if (done != -1) {
    for (int i = 1; i <= k; i++) {
      for (int j = i; j <= n; j += k) {
        if (i > done) {
          s[j - 1] = '0';
        }
      }
    }
  }
  cout << (int)s.size() << endl;
  cout << s << endl;
}

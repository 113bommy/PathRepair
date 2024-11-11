#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e18 + 7;
const long long int N = 2e5;
long long int power(long long int x, long long int y, long long int M = ::M) {
  x %= M;
  long long int ans = 1;
  while (y) {
    if (y & 1) ans = (ans * x) % M;
    y >>= 1LL;
    x = (x * x) % M;
  }
  return ans;
}
long long int add(long long int a, long long int b) {
  return ((a % M + b % M) % M);
}
long long int sub(long long int a, long long int b) {
  return ((a % M - b % M + M) % M);
}
long long int mul(long long int a, long long int b) {
  return (((a % M) * (b % M)) % M);
}
long long int divi(long long int a, long long int b) {
  return (mul(a, power(b, M - 2)) % M);
}
inline void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  k--;
  int pos = -1;
  int ch = char(k + 'a');
  char ch1;
  for (int i = n - 1; i >= 0; i--) {
    for (char j = s[i] + 1; j <= ch; j++) {
      if (i - 2 < 0 && i - 1 < 0 && j != s[i - 1]) {
        pos = i;
        ch1 = j;
        break;
      }
      if (i - 2 < 0 && i - 1 >= 0 && j != s[i - 1]) {
        pos = i;
        ch1 = j;
        break;
      } else if (i - 2 >= 0 && j != s[i - 1] && j != s[i - 2]) {
        pos = i;
        ch1 = j;
        break;
      }
    }
    if (pos >= 0) break;
  }
  if (pos == -1) {
    cout << "NO";
    return;
  }
  s[pos] = ch1;
  for (int i = pos + 1; i < n; i++) {
    for (char j = 'a'; j <= 'z'; j++) {
      if (i - 2 < 0 && i - 1 >= 0 && j != s[i - 1]) {
        s[i] = j;
        break;
      }
      if (i - 2 >= 0 && j != s[i - 1] && j != s[i - 2]) {
        s[i] = j;
        break;
      }
    }
  }
  cout << s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}

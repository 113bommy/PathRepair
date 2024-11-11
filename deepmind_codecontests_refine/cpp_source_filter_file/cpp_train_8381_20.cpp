#include <bits/stdc++.h>
using namespace std;
const long double EPS = 3e-16;
const long long MAXN = (1e4 + 2);
const long long INF = 1e9 + 7;
void file() {
  freopen(
      "choose"
      ".in",
      "r", stdin);
  if (0)
    freopen(
        "choose"
        ".out",
        "w", stdout);
}
bool TPrime(long long n) {
  if (n < 2) return 0;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    int digit = int(s[i] - '0');
    if (digit % 4 == 0) ans++;
    if (i > 0) {
      int second = int(s[i - 1] - '0');
      if ((second * 10 + digit) % 4 == 0) ans += i;
    }
  }
  cout << ans;
  cout << endl;
  return 0;
}

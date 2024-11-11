#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int n, long long int m) {
  if (n == 0) return 1;
  if (n == 1) return x;
  long long int y = power(x, n / 2, m);
  y = (y * y) % m;
  if (n % 2) y *= x;
  return y % m;
}
const long long N = 5e3 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t, n, m, i, j, x, y;
  string s, w, ans;
  char c;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    ans = s;
    x = 1;
    for (i = 1; i < n; i++) {
      w = "";
      for (j = i; j < n; j++) w += s[j];
      if ((n - i) % 2 == 0) {
        for (j = 0; j < i; j++) w += s[j];
      } else {
        for (j = i - 1; j >= 0; j--) w += s[j];
      }
      if (ans > w) {
        x = i + 1;
        ans = w;
      }
    }
    cout << ans << endl << x << endl;
  }
  return 0;
}

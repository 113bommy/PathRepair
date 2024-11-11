#include <bits/stdc++.h>
using namespace std;
int long long n, a, b, ans, i, j, p[15], k;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  cin >> s;
  a = 1;
  b = 26;
  for (i = 0; i < n; i++) {
    j = int(s[i]) - 96;
    if (j - a > b - j) {
      if (j - a <= k) {
        s[i] = 'a';
        k -= j - a;
      } else {
        s[i] = char(j + k + 96);
        k = 0;
      }
    } else {
      if (b - j <= k) {
        s[i] = 'z';
        k -= b - j;
      } else {
        s[i] = char(j + k + 96);
        k = 0;
      }
    }
  }
  if (k == 0)
    cout << s << endl;
  else
    cout << -1;
}

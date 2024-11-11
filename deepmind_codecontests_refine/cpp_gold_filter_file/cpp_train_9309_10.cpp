#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, c, d, k, tot, x, y, t, r, p, l, a[1001][1001];
string s[10000];
int main() {
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n >> l >> r;
    if (n / l * r >= n)
      s[i] = "Yes";
    else
      s[i] = "No";
  }
  for (int i = 1; i <= t; i++) cout << s[i] << endl;
  return 0;
}

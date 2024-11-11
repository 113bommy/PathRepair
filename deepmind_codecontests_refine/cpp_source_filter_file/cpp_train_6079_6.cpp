#include <bits/stdc++.h>
using namespace std;
int n, a[2111111];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  string s;
  cin >> s;
  n = s.size();
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == s[i + 1]) a[i + 1]++;
  }
  for (int i = 1; i <= n + 1; i++) {
    a[i] += a[i - 1];
  }
  int m, l, r;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> l >> r;
    cout << a[r - 1] - a[l - 1];
  }
  return 0;
}

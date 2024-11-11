#include <bits/stdc++.h>
using namespace std;
int q, n, k;
string solve(int n, int k) {
  string s;
  int m = n / k;
  for (int i = 1; i < k; i++) {
    for (int j = 1; j <= m; j++) s += char('a' + i - 1);
  }
  for (int i = 1; i <= n - m * (k - 1); i++) s += char('a' + k - 1);
  return s;
}
int main() {
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> n >> k;
    cout << solve(n, k);
    cout << endl;
  }
  return 0;
}

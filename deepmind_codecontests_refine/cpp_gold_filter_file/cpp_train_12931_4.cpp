#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, q, year, a1, a2;
  cin >> n >> m;
  string s[20], t[20];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < m; i++) cin >> t[i];
  cin >> q;
  while (q--) {
    cin >> year;
    a1 = (year % n) - 1;
    if (a1 == -1) a1 = n - 1;
    a2 = (year % m) - 1;
    if (a2 == -1) a2 = m - 1;
    cout << s[a1] << t[a2] << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  string t[m];
  string s[n];
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int q;
  long long a;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> a;
    cout << t[(a - 1) % m] << s[(a - 1) % n] << endl;
  }
  return 0;
}

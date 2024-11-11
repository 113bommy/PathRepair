#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  cin >> n >> m;
  string s1[n], s2[n];
  string a[m], b[m];
  for (i = 0; i < n; i++) cin >> s1[i] >> s2[i];
  for (i = 0; i < m; i++) cin >> a[i] >> b[i];
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (b[i] == (s2[j] + ";")) {
        cout << a[i] << " " << b[i] << " "
             << "#" << s1[j];
      }
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string a[m], b[m];
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
  }
  string t[n];
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    string h1 = t[i];
    for (int j = 0; j < m; j++) {
      if (h1 == a[j]) {
        string h2 = a[j];
        string h3 = b[j];
        int k = h2.size();
        int k2 = h3.size();
        if (k < k2) {
          cout << h2 << " ";
          break;
        } else {
          cout << h3 << " ";
          break;
        }
      }
    }
  }
  return 0;
}

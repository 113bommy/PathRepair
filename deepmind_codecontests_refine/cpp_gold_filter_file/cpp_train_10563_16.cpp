#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string a[m], b[m], lec[n];
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> lec[i];
    for (int j = 0; j < m; j++) {
      if (lec[i] == a[j]) {
        if (a[j].length() > b[j].length()) lec[i] = b[j];
        break;
      }
    }
  }
  for (int j = 0; j < n; j++) cout << lec[j] << " ";
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p = 2;
  cin >> n;
  int c[n], d[n];
  for (int i = 0; i < n; i++) {
    cin >> c[i] >> d[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((c[i] + d[i]) == c[j] && (c[j] + d[j]) == c[i]) {
        cout << "YES";
        p = 1;
        break;
      }
      if (p == 1) break;
    }
    if (p == 1) break;
  }
  if (p == 2) {
    cout << "NO";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string x[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    int a = 0, b = x[i].length() - 1;
    if (x[i].length() > 10) {
      cout << x[i][a] << x[i].length() - 2 << x[i][b] << endl;
    } else
      cout << x[i] << endl;
  }
  return 0;
}

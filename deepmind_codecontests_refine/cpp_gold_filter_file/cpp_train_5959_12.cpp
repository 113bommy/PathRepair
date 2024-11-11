#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> m >> n >> k;
  cout << n - 1 + m - 1 + m * n << endl;
  for (int i = 0; i < 2 * k; i++) {
    int a, b;
    cin >> a >> b;
  }
  for (int i = 0; i < m - 1; i++) cout << "U";
  for (int i = 0; i < n - 1; i++) cout << "L";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (i % 2 == 0)
        cout << "R";
      else
        cout << "L";
    }
    cout << "D";
  }
  return 0;
}

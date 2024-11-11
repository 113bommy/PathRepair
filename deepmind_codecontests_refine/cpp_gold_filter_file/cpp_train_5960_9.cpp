#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int x[k], y[k], fx[k], fy[k];
  for (int i = 0; i < k; i++) cin >> x[i] >> y[i];
  for (int i = 0; i < k; i++) cin >> fx[i] >> fy[i];
  cout << (n * m) + n + m - 3 << endl;
  for (int i = 0; i < m - 1; i++) cout << "L";
  for (int i = 0; i < n - 1; i++) cout << "U";
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      for (int j = 0; j < m - 1; j++) cout << "R";
    else
      for (int j = 0; j < m - 1; j++) cout << "L";
    if (i != n - 1) cout << "D";
  }
  return 0;
}

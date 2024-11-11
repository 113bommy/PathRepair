#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, k, p, c = 0, d = 0;
  cin >> n >> m >> k;
  p = k;
  long long sx[k], sy[k], fx[k], fy[k];
  while (p--) {
    cin >> sx[c++] >> sy[d++];
  }
  p = k;
  c = 0;
  d = 0;
  while (p--) {
    cin >> fx[c++] >> fy[d++];
  }
  cout << (n * m + n + m - 3) << "\n";
  for (int i = 0; i < n - 1; i++) cout << "U";
  for (int i = 0; i < m - 1; i++) cout << "L";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (i % 2)
        cout << "R";
      else
        cout << "L";
    }
    if (i < n - 1)
      cout << "D";
    else
      break;
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  int t[100000][3];
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> t[i][0] >> t[i][1] >> t[i][2];
  }
  int total = 0;
  for (int i = 0; i < k; i++) {
    int b;
    cin >> b;
    for (int j = 0; j < m; j++) {
      if (t[j][0] <= b && b <= t[j][1]) total += b - t[j][0] + t[j][2];
    }
  }
  cout << total << endl;
  return 0;
}

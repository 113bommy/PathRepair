#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int pass[n], notPass[m];
  for (int i = 0; i < n; i++) cin >> pass[i];
  for (int i = 0; i < m; i++) cin >> notPass[i];
  int minpass = INT_MAX, maxpass = pass[0];
  for (int i = 0; i < n; i++) {
    if (maxpass < pass[i]) maxpass = pass[i];
    if (minpass > pass[i]) minpass = pass[i];
  }
  int max1 = max(2 * minpass, maxpass);
  for (int i = 0; i < m; i++) {
    if (max1 >= notPass[i]) {
      cout << "-1" << endl;
      return 0;
    }
  }
  cout << max1 << endl;
  return 0;
}

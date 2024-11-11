#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char arr[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  int maxi = -1, mini = 1001, maxj = -1, minj = 1001;
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 'B') {
        maxi = max(maxi, i);
        maxj = max(maxj, j);
        mini = min(mini, i);
        minj = min(minj, j);
        count++;
      }
    }
  }
  if (count == 0) {
    cout << "1"
         << "\n";
    return 0;
  }
  int diffi = maxi - mini + 1;
  int diffj = maxj - minj + 1;
  int maxdiff = max(diffi, diffj);
  if (diffi > diffj) {
    int k = m - diffj;
    if (k >= (diffi - diffj)) {
      cout << ((diffi * diffi) - count) << "\n";
      return 0;
    } else {
      cout << "-1"
           << "\n";
      return 0;
    }
  } else if (diffj > diffi) {
    int p = n - diffi;
    if (p >= (diffj - diffi)) {
      cout << ((diffj * diffj) - count) << "\n";
      return 0;
    } else {
      cout << "-1"
           << "\n";
      return 0;
    }
  } else if (diffj == diffi) {
    cout << ((diffi * diffi) - count) << "\n";
    return 0;
  }
}

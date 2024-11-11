#include <bits/stdc++.h>
using namespace std;
int val[102] = {0};
int main() {
  int n, m, max = INT_MIN, idx;
  cin >> n >> m;
  long long int arr[n + 1][m + 1];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      if (max < arr[i][j]) {
        max = arr[i][j];
        idx = j;
      }
    }
    val[idx]++;
    max = INT_MIN;
  }
  max = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (max < val[i]) {
      max = val[i];
      idx = i;
    }
  }
  cout << idx + 1 << endl;
  return 0;
}

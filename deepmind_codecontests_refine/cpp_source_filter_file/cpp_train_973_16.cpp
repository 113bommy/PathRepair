#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int arr[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> arr[i][j];
  for (int i = 0; i < n; i++) {
    int a = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      a ^= arr[i][j];
    }
    cout << a << " ";
  }
  return 0;
}

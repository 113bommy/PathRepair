#include <bits/stdc++.h>
using namespace std;
int arr[31][31];
int R[31], L[31];
int main() {
  int n;
  cin >> n;
  int pos1 = 0, pos2 = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> arr[i][j];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int sum1 = 0, sum2 = 0;
    for (int j = 0; j < n; ++j) {
      sum1 += arr[i][j];
      sum2 += arr[j][i];
    }
    R[pos1++] = sum1;
    L[pos2++] = sum2;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      if (R[i] < L[j]) ans++;
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, a[50010][10], ans[50010][10];
  cin >> M >> N;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (i == 0 and j == 0) {
        ans[i][j] = a[i][j];
      } else if (i == 0) {
        ans[i][j] = a[i][j] + ans[i][j - 1];
      } else if (j == 0) {
        ans[i][j] = a[i][j] + ans[i - 1][j];
      } else {
        ans[i][j] = a[i][j] + max(ans[i][j - 1], ans[i - 1][j]);
      }
    }
  }
  for (int i = 0; i < M; i++) {
    cout << a[i][N - 1] << " ";
  }
}

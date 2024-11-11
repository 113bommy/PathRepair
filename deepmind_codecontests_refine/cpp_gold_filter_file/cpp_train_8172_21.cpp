#include <bits/stdc++.h>
using namespace std;
int mat[1001][1001];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    mat[x][y] = 1;
  }
  long long int ans = 0;
  for (int i = 1; i < 1000; i++) {
    int j = i, k = 1, count = 0;
    while (j <= 1000 && k <= 1000) {
      if (mat[j][k] == 1) count++;
      j++;
      k++;
    }
    ans += ((count) * (count - 1)) / 2;
  }
  for (int i = 2; i < 1000; i++) {
    int j = i, k = 1, count = 0;
    while (j <= 1000 && k <= 1000) {
      if (mat[k][j] == 1) count++;
      j++;
      k++;
    }
    ans += ((count) * (count - 1)) / 2;
  }
  for (int i = 1000; i >= 0; i--) {
    int j = i, k = 1, count = 0;
    while (j >= 0 && k <= 1000) {
      if (mat[j][k] == 1) count++;
      j--;
      k++;
    }
    ans += ((count) * (count - 1)) / 2;
  }
  for (int i = 2; i <= 1000; i++) {
    int j = i, k = 1000, count = 0;
    while (j <= 1000 && k >= 0) {
      if (mat[k][j] == 1) count++;
      j++;
      k--;
    }
    ans += ((count) * (count - 1)) / 2;
  }
  cout << ans << endl;
  return 0;
}

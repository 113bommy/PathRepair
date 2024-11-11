#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, c;
  cin >> n >> k;
  char arr[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];
    }
  }
  int occ[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      occ[i][j] = 0;
    }
  }
  int count;
  int maxx = 0;
  int row = 1, col = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= (n - k + 1); j++) {
      count = 0;
      c = 0;
      for (int l = j; c < k; l++, c++) {
        if (arr[i][l] == '.') {
          count++;
        }
      }
      c = 0;
      if (count == k) {
        for (int l = j; c < k; l++, c++) {
          occ[i][l]++;
          if (occ[i][l] > maxx) {
            maxx = occ[i][l];
            row = i;
            col = l;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= (n - k + 1); j++) {
      count = 0;
      c = 0;
      for (int l = j; c < k; l++, c++) {
        if (arr[l][i] == '.') {
          count++;
        }
      }
      c = 0;
      if (count == k) {
        for (int l = j; c < k; l++, c++) {
          occ[l][i]++;
          if (occ[l][i] > maxx) {
            maxx = occ[l][i];
            row = l;
            col = i;
          }
        }
      }
    }
  }
  cout << row << " " << col << endl;
}

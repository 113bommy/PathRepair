#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, a, b, c;
  cin >> n >> m >> k;
  long long int mat[n][m];
  int info_r[n];
  int info_c[m];
  for (int i = 0; i < n; i++) info_r[i] = -1;
  for (int j = 0; j < n; j++) info_c[j] = -1;
  long long int colours[k];
  for (int i = 0; i < k; i++) {
    cin >> a >> b >> colours[i];
    if (a == 1) {
      info_r[b - 1] = i;
    } else {
      info_c[b - 1] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    int q1 = info_r[i];
    for (int j = 0; j < m - 1; j++) {
      int maxi = max(q1, info_c[j]);
      if (maxi == -1)
        mat[i][j] = 0;
      else
        mat[i][j] = colours[maxi];
      cout << mat[i][j] << " ";
    }
    int maxi = max(q1, info_c[m - 1]);
    if (maxi == -1)
      mat[i][m - 1] = 0;
    else
      mat[i][m - 1] = colours[maxi];
    cout << mat[i][m - 1] << endl;
  }
  return 0;
}

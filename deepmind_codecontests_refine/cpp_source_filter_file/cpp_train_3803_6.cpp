#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 100;
constexpr int q_max = 10000;
const long double PI = acos(-1.0);
int mat[MAX][MAX];
int qq[q_max][4];
int main() {
  long long n, m, q;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> q;
  long long i, j;
  for (i = 0; i < q; i++) {
    int t1;
    cin >> t1;
    qq[i][0] = t1;
    if (t1 == 1 || t1 == 2) {
      cin >> qq[i][1];
    } else {
      cin >> qq[i][1] >> qq[i][2] >> qq[i][3];
    }
  }
  for (i = q - 1; i >= 0; i--) {
    if (qq[i][0] == 3) {
      mat[qq[i][1] - 1][qq[i][2] - 1] = qq[i][3];
    } else if (qq[i][0] == 1) {
      int str = qq[i][1] - 1;
      int last = mat[str][n - 1];
      for (j = n - 1; j >= 0; j--) mat[str][j] = mat[str][j - 1];
      mat[str][0] = last;
    } else if (qq[i][0] == 2) {
      int st = qq[i][1] - 1;
      int last = mat[m - 1][st];
      for (j = m - 1; j >= 0; j--) mat[j][st] = mat[j - 1][st];
      mat[0][st] = last;
    }
  }
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) cout << mat[i][j] << " ";
    cout << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using namespace std;
using namespace std;
using namespace std;
using namespace std;
double p[20][20], dp[1 << 20][20];
int main() {
  int m, i, j, k;
  dp[1][0] = 1;
  cin >> m;
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) cin >> p[i][j];
  for (i = 0; i < (1 << m); i++)
    for (j = 0; j < m; j++)
      for (k = 0; k < m; k++)
        if (i & (1 << k) && k != j)
          dp[i][j] = max(dp[i][j], p[j][k] * dp[i ^ (1 << k)][j] +
                                       p[k][j] * dp[i ^ (1 << j)][k]);
  printf("%.12f\n", *max_element(dp[(1 << m) - 1], dp[(1 << m) - 1] + m));
}

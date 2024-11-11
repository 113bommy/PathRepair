#include <bits/stdc++.h>
using namespace std;
int n, m, k;
string a, b;
int d[1010][1010][11];
int comp[1010][1010];
void fill_comp();
int find_ans();
int main() {
  scanf("%d%d%d", &n, &m, &k);
  cin >> a >> b;
  a = '*' + a;
  b = '*' + b;
  fill_comp();
  printf("%d", find_ans());
}
void fill_comp() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i] == b[j]) comp[i][j] = comp[i - 1][j - 1] + 1;
}
int find_ans() {
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int l = 1; l <= k; l++) {
        d[i][j][l] = max(d[i][j][l - 1], max(d[i - 1][j][l], d[i][j - 1][l]));
        int dis = comp[i][j];
        d[i][j][l] = max(d[i][j][l], d[i - dis][j - dis][l - 1] + dis);
        ans = max(ans, d[i][j][l]);
      }
  return ans;
}

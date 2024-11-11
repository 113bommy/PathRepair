#include <bits/stdc++.h>
using namespace std;
const int MAX = 2000 + 10;
int n, k;
int g[MAX][MAX];
long double ans;
int main() {
  int i, j;
  scanf("%d%d", &n, &k);
  for ((i) = (1); (i) <= (n); ++(i)) {
    g[i][i] = -1;
    for ((j) = (i + 1); (j) <= (n); ++(j)) {
      scanf("%d", &g[i][j]);
      g[j][i] = g[i][j];
    }
  }
  for ((i) = (1); (i) <= (n); ++(i)) {
    long long all = 0;
    int num = 0;
    for ((j) = (1); (j) <= (n); ++(j))
      if (g[i][j] != -1) {
        ++num;
        all += g[i][j];
      }
    if (num < k) continue;
    long double cc = (long double)all * k;
    for (j = n - num; j >= 1; --j) {
      cc /= num + j;
      cc *= num - k + j;
    }
    ans += cc / num;
  }
  cout << (long long)ans << endl;
  return 0;
}

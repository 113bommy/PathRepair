#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int maxn = 2010;
int a[maxn][maxn] = {};
int invrow[maxn] = {};
int invcol[maxn] = {};
int n;
int xs[maxn] = {};
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c = -1;
      while (c != '0' && c != '1') c = getchar();
      if (c == '1')
        a[i][j] = 1;
      else
        a[i][j] = 0;
      if (i == j) xs[i] = a[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int curinv = 0;
    for (int j = n - 1; j > i; --j) {
      int cur = a[i][j] ^ invrow[j] ^ curinv;
      if (cur == 1) {
        curinv ^= 1;
        invrow[j] ^= 1;
        ans++;
        xs[i] ^= 1;
        xs[j] ^= 1;
      }
      a[i][j] = 0;
    }
    curinv = 0;
    for (int j = n - 1; j > i; --j) {
      int cur = a[j][i] ^ invcol[j] ^ curinv;
      if (cur == 1) {
        curinv ^= 1;
        invcol[j] ^= 1;
        ans++;
        xs[i] ^= 1;
        xs[j] ^= 1;
      }
      a[j][i] = 0;
    }
  }
  for (int i = 0; i < n; ++i) ans += xs[i];
  printf("%d", ans);
  return 0;
}

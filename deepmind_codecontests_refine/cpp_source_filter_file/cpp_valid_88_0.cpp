#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx", "sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
using namespace std;
int a[910];
int b[910];
int seats[310][310];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < m; ++i) {
        seats[j][i] = -1;
        scanf("%d", &(a[m * j + i]));
        b[m * j + i] = a[m * j + i];
      }
    }
    sort(a, a + n * m);
    unordered_map<int, pair<int, int> > M;
    int last = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i * m + j] != last) {
          last = a[i * m + j];
          M[a[i * m + j]] = {i, j};
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n * m; ++i) {
      int bi = b[i];
      auto [row, col] = M[bi];
      M[bi] = {col + 1 < m ? pair<int, int>{row, col + 1}
                           : pair<int, int>{row + 1, 0}};
      for (int k = 0; k <= col; ++k)
        ans += (seats[row][k] < b[i] and seats[row][k] != -1);
      seats[row][col] = bi;
    }
    printf("%d \n", ans);
  }
}

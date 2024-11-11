    #include <cstdio>
    int c[2000][2000];
    int main() {
      int n, m, k;
      int x = 0, y = 0;
      scanf("%d%d%d", &n, &m, &k);
      for (int i = 0; i < k; ++i) {
        int a;
        scanf("%d", &a);
        while (a--) {
          c[x][y] = i + 1;
          if (~x & 1) y < m - 1 ? ++y : ++x;
          else y > 0 ? --y : ++x;
        }
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
          printf("%d ", c[i][j]);
        printf("\n");
      }
      return 0;
    }
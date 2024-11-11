#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
int mat[1010][1010];
int row[1010][1010], col[1010][1010];
int main() {
  int n, m, k, tot = 0, sum = 0;
  char c;
  cin >> n >> m >> k;
  for (int i = 0; i < n * 2 - 1; i++) {
    if (i & 1) {
      for (int j = 0; j < m; j++) {
        scanf(" %c", &c);
        tot++;
        col[j][i >> 1] = (c == 'N');
        sum += col[j][i >> 1];
      }
    } else {
      for (int j = 0; j < m - 1; j++) {
        scanf(" %c", &c);
        tot++;
        row[i >> 1][j] = (c == 'N');
        sum += row[i >> 1][j];
      }
    }
  }
  if (k == 1) {
    if (sum * 4 > tot)
      puts("NO");
    else {
      puts("YES");
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("1 ");
        puts("");
      }
    }
    return 0;
  }
  puts("YES");
  if (n <= m) {
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      if (i) cnt += mat[i - 1][0] ^ col[0][i - 1];
      for (int j = 1; j < m; j++) {
        mat[i][j] = mat[i][j - 1] ^ row[i][j - 1];
        if (i) cnt += (mat[i][j] != mat[i - 1][j]) ^ col[j][i - 1];
      }
      if (cnt * 2 > m) {
        for (int j = 0; j < m; j++) mat[i][j] ^= 1;
      }
    }
  } else {
    for (int j = 0; j < m; j++) {
      int cnt = 0;
      if (j) cnt += mat[0][j - 1] ^ row[0][j - 1];
      for (int i = 1; i < n; i++) {
        mat[i][j] = mat[i - 1][j] ^ col[j][i - 1];
        if (j) cnt += (mat[i][j] != mat[i][j - 1]) ^ row[i][j - 1];
      }
      if (cnt * 2 > n) {
        for (int i = 0; i < n; i++) mat[i][j] ^= 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", mat[i][j] + 1);
    }
    puts("");
  }
  return 0;
}

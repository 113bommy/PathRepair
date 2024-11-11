#include <bits/stdc++.h>
using namespace std;
struct Mat {
  int n, m;
  long long mat[55][55];
  Mat() {
    memset(mat, 0, sizeof(mat));
    n = m = 55;
  };
};
Mat operator*(Mat a, Mat b) {
  Mat c;
  c = Mat();
  c.n = a.n, c.m = b.m;
  for (int i = 1; i <= a.n; i++) {
    for (int j = 1; j <= b.m; j++) {
      for (int k = 1; k <= a.m; k++) {
        c.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % 1000000007;
        c.mat[i][j] %= 1000000007;
      }
    }
  }
  return c;
}
Mat operator+(Mat a, Mat b) {
  Mat c;
  c = Mat();
  c.n = a.n, c.m = a.m;
  for (int i = 1; i <= a.n; i++) {
    for (int j = 1; j <= a.m; j++) {
      c.mat[i][j] = a.mat[i][j] + b.mat[i][j];
    }
  }
  return c;
}
Mat operator^(Mat a, long long k) {
  Mat c;
  int i, j;
  c = Mat();
  c.n = a.n, c.m = a.n;
  for (i = 1; i <= a.n; i++) c.mat[i][i] = 1;
  while (k) {
    if (k & (1LL)) {
      c = c * a;
    }
    a = a * a;
    k >>= (1LL);
  }
  return c;
}
void out(Mat a) {
  int i, j;
  for (i = 1; i <= a.n; i++) {
    for (j = 1; j <= a.m; j++) {
      cout << a.mat[i][j] << " ";
    }
    cout << endl;
  }
}
int main() {
  long long n;
  int m, k;
  cin >> n >> m >> k;
  Mat a, b;
  a = Mat(), b = Mat();
  int i, j;
  a.n = 1, a.m = m;
  for (i = 1; i <= m; i++) a.mat[1][i] = 1;
  b.n = m, b.m = m;
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= m; j++) {
      b.mat[i][j] = 1;
    }
  }
  while (k--) {
    char str[4];
    cin >> str;
    int x = islower(str[0]) ? str[0] - 'a' + 1 : str[0] - 'A' + 1;
    int y = islower(str[1]) ? str[1] - 'a' + 1 : str[1] - 'A' + 1;
    b.mat[x][y] = 0;
  }
  Mat c = b ^ (n - 1);
  long long ans = 0;
  a = a * c;
  for (i = 1; i <= m; i++) {
    ans += a.mat[1][i];
    ans %= 1000000007;
  }
  cout << ans << endl;
  return 0;
}

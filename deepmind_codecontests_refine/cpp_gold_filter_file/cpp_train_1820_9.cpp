#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int mat[N][N], temp1[N][N], temp2[N][N], base[N][N];
void copy(int a[N][N], int b[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      a[i][j] = b[i][j];
    }
  }
}
void add(int a[N][N], int b[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      a[i][j] = (a[i][j] + b[i][j]) % 1000000007;
    }
  }
}
void mul(int a[N][N], int b[N][N]) {
  memset(temp1, 0, sizeof temp1);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        temp1[i][j] = (temp1[i][j] + 1LL * a[i][k] * b[k][j]) % 1000000007;
      }
    }
  }
  copy(a, temp1);
}
void matpow(int n) {
  if (n == 0) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        mat[i][j] = i == j;
      }
    }
    return;
  }
  matpow(n / 2);
  copy(temp2, mat);
  mul(temp2, mat);
  if (n % 2) mul(temp2, base);
  copy(mat, temp2);
}
int n, first, a[101], dp[101], s[101];
void solve() {
  cin >> n >> first;
  for (int i = 1; i < n + 1; i++) {
    int w;
    cin >> w;
    a[w]++;
  }
  dp[0] = s[0] = 1;
  for (int i = 1; i < 101; i++) {
    for (int j = 1; j < i + 1; j++) {
      dp[i] = (1LL * dp[i - j] * a[j] + dp[i]) % 1000000007;
    }
    s[i] = (s[i - 1] + dp[i]) % 1000000007;
  }
  if (first < 100)
    cout << s[first] << '\n';
  else {
    mat[0][0] = a[1] + 1;
    for (int i = 2; i < 101; i++)
      mat[0][i - 1] = (a[i] - a[i - 1] + 1000000007) % 1000000007;
    mat[0][100] = (1000000007 - a[100]) % 1000000007;
    for (int i = 1; i < 101; i++) mat[i][i - 1] = 1;
    copy(base, mat);
    matpow(first - 100);
    int ans = 0;
    for (int i = 0; i < 101; i++)
      ans = (ans + 1LL * mat[0][i] * s[100 - i]) % 1000000007;
    cout << ans << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

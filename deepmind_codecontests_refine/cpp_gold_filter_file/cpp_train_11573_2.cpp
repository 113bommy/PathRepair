#include <bits/stdc++.h>
using namespace std;
const int col[4] = {6, 9, 9, 6};
const int row[2] = {3, 12};
const int MOD = 1000003;
const int MAXN = 1000000;
int a[MAXN], b[MAXN];
vector<string> matrix;
char mat[MAXN];
int powmod(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = (long long)ret * a % MOD;
    a = (long long)a * a % MOD;
    b >>= 1;
  }
  return ret;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    a[i] = 15;
    b[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", mat);
    matrix.push_back(mat);
  }
  int ret = 0;
  for (int j = 0; j < m; ++j) {
    a[j] = 0;
    b[j] = 0;
  }
  for (int j = 0; j < n; ++j) {
    for (int k = 0; k < m; ++k) {
      if (matrix[j][k] != '.') {
        int val = matrix[j][k] - '1';
        int tx = -1, ty = -1;
        if (val == 0) {
          tx = (j & 1) ^ 1;
          ty = (k & 1) ^ 1;
        } else if (val == 1) {
          tx = (j & 1);
          ty = (k & 1) ^ 1;
        } else if (val == 2) {
          tx = (j & 1);
          ty = (k & 1);
        } else {
          tx = (j & 1) ^ 1;
          ty = (k & 1);
        }
        a[k] |= 1 << tx;
        b[j] |= 1 << ty;
      }
    }
  }
  int cnt = 0;
  bool flag = true;
  for (int j = 0; j < m; ++j) {
    if (a[j] == 3) {
      flag = false;
    } else if (a[j] == 0) {
      ++cnt;
    }
  }
  for (int j = 0; j < n; ++j) {
    if (b[j] == 3) {
      flag = false;
    } else if (b[j] == 0) {
      ++cnt;
    }
  }
  if (!flag)
    puts("0");
  else {
    ret = (ret + powmod(2, cnt)) % MOD;
    printf("%d\n", ret);
  }
  return 0;
}

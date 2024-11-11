#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, q;
int psum[N][N][4];
int get(char c) {
  if (c == 'R') return 0;
  if (c == 'G') return 1;
  if (c == 'Y') return 2;
  if (c == 'B') return 3;
  assert(0);
  return 0;
}
int sum(int i, int j, int c, int d, int k) {
  return psum[c][d][k] - psum[i - 1][d][k] - psum[c][j - 1][k] +
         psum[i - 1][j - 1][k];
}
bool is_ans(int i, int j, int len) {
  if (sum(i, j, i + len - 1, j + len - 1, 0) != len * len) return false;
  if (sum(i, j + len, i + len - 1, j + 2 * len - 1, 1) != len * len)
    return false;
  if (sum(i + len, j, i + 2 * len - 1, j + len - 1, 2) != len * len)
    return false;
  if (sum(i + len, j + len, i + 2 * len - 1, j + 2 * len - 1, 3) != len * len)
    return false;
  return true;
}
int mat[N][N];
int getsum(int a, int b, int c, int d) {
  return mat[c][d] - mat[a - 1][d] - mat[c][b - 1] + mat[a - 1][b - 1];
}
void build(int len) {
  memset(mat, 0, sizeof mat);
  for (int i = 1; i + 2 * len - 1 <= n; i++) {
    for (int j = 1; j + 2 * len - 1 <= m; j++) {
      mat[i][j] = is_ans(i, j, len);
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
    }
}
const int Q = 300005;
int r1[Q], c1[Q], r2[Q], c2[Q];
int ans[Q];
void solve(int L, int R, vector<int> ids) {
  if (ids.empty() or L > R) return;
  int mid = (L + R) / 2;
  vector<int> lef, rig;
  build(mid);
  for (int id : ids) {
    int a = r1[id], b = c1[id];
    int c = r2[id] - 2 * mid + 1, d = c2[id] - 2 * mid + 1;
    if (c < a or d < b or getsum(a, b, c, d) == 0) {
      lef.push_back(id);
    } else {
      ans[id] = mid * mid * 4;
      rig.push_back(id);
    }
  }
  solve(L, mid - 1, lef);
  solve(mid + 1, R, rig);
}
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      scanf(" %c", &c);
      for (int k = 0; k < 4; k++) {
        psum[i][j][k] += psum[i - 1][j][k];
        psum[i][j][k] += psum[i][j - 1][k];
        psum[i][j][k] -= psum[i - 1][j - 1][k];
      }
      psum[i][j][get(c)]++;
    }
  }
  vector<int> ids;
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d %d", r1 + i, c1 + i, r2 + i, c2 + i);
    ids.push_back(i);
  }
  solve(1, min(n, m) / 2, ids);
  for (int i = 0; i < q; i++) {
    printf("%d\n", ans[i]);
  }
}

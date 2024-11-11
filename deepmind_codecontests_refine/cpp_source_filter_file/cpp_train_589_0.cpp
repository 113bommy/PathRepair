#include <bits/stdc++.h>
using namespace std;
const int maxn = 201;
const int logn = 10;
struct matrix {
  double a[maxn][maxn];
  int n;
  bool is_vec;
  matrix() {}
  void init(int n) {
    this->n = n;
    is_vec = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        a[i][j] = 0;
      }
    }
  }
  matrix operator*(const matrix &m2) const {
    matrix ans;
    ans.init(n);
    if (is_vec) {
      ans.is_vec = 1;
      for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
          ans.a[1][j] += a[1][k] * m2.a[j][k];
        }
      }
      return ans;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
          ans.a[i][j] += a[i][k] * m2.a[k][j];
        }
      }
    }
    return ans;
  }
};
matrix A[logn];
int n;
int px[maxn], py[maxn];
vector<int> p[maxn][maxn];
int cnt[maxn];
bool vis[maxn][maxn];
void init();
double cal(int t, int m);
bool is_line(int a, int b, int c);
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &px[i], &py[i]);
  }
  init();
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, m;
    scanf("%d%d", &t, &m);
    printf("%.7lf\n", cal(t, m));
  }
  return 0;
}
double cal(int t, int m) {
  m--;
  matrix f;
  f.init(n);
  f.is_vec = 1;
  f.a[1][t] = 1;
  for (int i = 0; i < logn; i++) {
    if ((m >> i) & 1) {
      f = f * A[i];
    }
  }
  double max_ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= cnt[i]; j++) {
      double cur_ans = 0;
      for (int u : p[i][j]) {
        cur_ans += f.a[1][u];
      }
      cur_ans /= p[i][j].size();
      max_ans = max(max_ans, cur_ans);
    }
  }
  return max_ans;
}
void init() {
  vector<int> cur;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j || vis[i][j]) continue;
      cur.clear();
      cur.push_back(i);
      cur.push_back(j);
      for (int k = 1; k <= n; k++) {
        if (i == k || j == k || !is_line(i, j, k)) continue;
        cur.push_back(k);
      }
      for (int a : cur) {
        vis[i][a] = 1;
      }
      p[i][++cnt[i]] = cur;
    }
  }
  A[0].init(n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= cnt[i]; j++) {
      for (int a : p[i][j]) {
        A[0].a[i][a] += 1.0 / cnt[i] / p[i][j].size();
      }
    }
  }
  for (int i = 1; i < logn; i++) {
    A[i] = A[i - 1] * A[i - 1];
  }
}
bool is_line(int a, int b, int c) {
  int x1 = px[b] - px[a];
  int x2 = px[c] - px[a];
  int y1 = py[b] - py[a];
  int y2 = py[c] - py[a];
  return (long long)x1 * y2 - (long long)x2 * y1 == 0;
}

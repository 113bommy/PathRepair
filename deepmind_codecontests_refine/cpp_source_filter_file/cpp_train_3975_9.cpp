#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
struct subj {
  int id;
  int comp;
  long long a, b;
};
bool cmp(const subj& A, const subj& B) {
  if (A.comp != B.comp) return A.comp < B.comp;
  if (A.b != B.b) return A.b < B.b;
  return A.a < B.a;
}
int n, m, k;
subj d[50];
long long dp[51][51][102];
long long go(int i, int j, int add) {
  if (j == m) return -1000000000000000000LL;
  if (dp[i][j][add] != -1) return dp[i][j][add];
  long long ret = -1000000000000000000LL;
  long long sum = d[j].a + add;
  if (i == n) return sum;
  if (j == m - 1) return -1000000000000000000LL;
  for (int j2 = j + 1; j2 < m; j2++)
    if (d[j2].comp > d[j].comp) {
      long long val = sum + k;
      if (val == 0) val = 101;
      if (d[j2].a <= val && val <= d[j2].b)
        ret = max(ret, go(i + 1, j2, val - d[j2].a) + sum);
      val = sum * k;
      if (val == 0) val = 101;
      if (d[j2].a <= val && val <= d[j2].b)
        ret = max(ret, go(i + 1, j2, val - d[j2].a) + sum);
    }
  return dp[i][j][add] = ret;
}
void print(int i, int j, int add) {
  long long ret = dp[i][j][add];
  long long sum = d[j].a + add;
  cout << d[j].id + 1 << " " << sum << endl;
  if (i == n) return;
  for (int j2 = j + 1; j2 < m; j2++)
    if (d[j2].comp > d[j].comp) {
      long long val = sum + k;
      if (val == 0) val = 101;
      if (d[j2].a <= val && val <= d[j2].b)
        if (go(i + 1, j2, val - d[j2].a) + sum == ret) {
          print(i + 1, j2, val - d[j2].a);
          return;
        }
      val = sum * k;
      if (val == 0) val = 101;
      if (d[j2].a <= val && val <= d[j2].b)
        if (go(i + 1, j2, val - d[j2].a) + sum == ret) {
          print(i + 1, j2, val - d[j2].a);
          return;
        }
    }
}
void solution() {
  cin >> n >> m >> k;
  for (int i = 0, _n = (m); i < _n; ++i) {
    cin >> d[i].a >> d[i].b >> d[i].comp;
    d[i].id = i;
  }
  sort(d, d + m, cmp);
  memset((dp), (-1), sizeof((dp)));
  long long ret = -1000000000000000000LL;
  for (int i = 0, _n = (n); i < _n; ++i)
    for (int it = 0, _n = (d[i].b - d[i].a + 1); it < _n; ++it)
      ret = max(ret, go(1, i, it));
  if (ret < 0)
    puts("NO");
  else {
    puts("YES");
    for (int i = 0, _n = (n); i < _n; ++i)
      for (int it = 0, _n = (d[i].b - d[i].a + 1); it < _n; ++it)
        if (ret == go(1, i, it)) {
          print(1, i, it);
          return;
        }
  }
}
int main() {
  solution();
  return 0;
}

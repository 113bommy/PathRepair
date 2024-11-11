#include <bits/stdc++.h>
using namespace std;
inline void fre1() { freopen("input.txt", "r", stdin); }
inline void fre2() { fclose(stdin); }
const int MAXN = 2000 + 5;
const double EPS = 1e-8;
vector<pair<int, int> > vec[MAXN];
int n, m, k;
int val[MAXN][MAXN];
long long tr[MAXN][MAXN];
bool flag[MAXN], on[MAXN];
char op[10];
void add(int x, int y, int v) {
  for (; x <= n; x += (x & (-x)))
    for (int j = y; j <= m; j += (j & (-j))) tr[x][j] += v;
}
long long query(int x, int y) {
  long long ret = 0;
  for (; x; x -= (x & (-x)))
    for (int j = y; j; j -= (j & (-j))) ret += tr[x][j];
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int len, x, y, w;
  for (int i = 0; i < k; ++i) {
    scanf("%d", &len);
    while (len--) {
      scanf("%d%d%d", &x, &y, &w);
      val[x][y] = w;
      add(x, y, w);
      vec[i].push_back(make_pair(x, y));
    }
    flag[i] = on[i] = true;
  }
  scanf("%d", &len);
  int x2, y2;
  while (len--) {
    scanf("%s", op);
    if (op[0] == 'S') {
      scanf("%d", &x);
      flag[x] ^= true;
    } else {
      scanf("%d%d%d%d", &x, &y, &x2, &y2);
      for (int i = 0; i < k; ++i) {
        if (flag[i] == on[i]) continue;
        int fuhao = (flag[i] ? 1 : -1);
        for (int j = 0; j < vec[i].size(); ++j) {
          add(vec[i][j].first, vec[i][j].second,
              fuhao * val[vec[i][j].first][vec[i][j].second]);
        }
        on[i] = flag[i];
      }
      long long sum1 = query(x - 1, y - 1);
      long long sum2 = query(x - 1, y2);
      long long sum3 = query(x2, y - 1);
      long long sum4 = query(x2, y2);
      printf("%I64d\n", sum4 - sum3 - sum2 + sum1);
    }
  }
  return 0;
}

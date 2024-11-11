#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10, MAXNM = 2010, KMAX = 12;
int n, m, k, s;
int q[MAX];
int an[MAXNM][MAXNM];
int mm[KMAX][4];
int max_dis[KMAX][KMAX];
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int num = (1); num <= (k); ++num)
    for (int d = (0); d <= (3); ++d) mm[num][d] = INT_MIN;
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) {
      scanf("%d", &an[i][j]);
      auto& term = mm[an[i][j]];
      term[0] = max(term[0], i + j);
      term[1] = max(term[1], -(i + j));
      term[2] = max(term[2], i - j);
      term[3] = max(term[3], -(i - j));
    }
  for (int i = (1); i <= (s); ++i) scanf("%d", &q[i]);
  for (int num_1 = (1); num_1 <= (k); ++num_1) {
    for (int num_2 = (num_1 + 1); num_2 <= (k); ++num_2) {
      max_dis[num_1][num_2] =
          max({mm[num_1][0] + mm[num_2][1], mm[num_2][0] + mm[num_1][1],
               mm[num_1][2] + mm[num_2][3], mm[num_2][2] + mm[num_1][3]});
    }
  }
  int ans = INT_MIN;
  for (int pos = (2); pos <= (s); ++pos) {
    int a = q[pos - 1], b = q[pos];
    if (a > b) swap(a, b);
    ans = max(ans, max_dis[a][b]);
  }
  printf("%d\n", ans);
  return 0;
}

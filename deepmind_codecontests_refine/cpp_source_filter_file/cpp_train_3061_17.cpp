#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 7;
const int N = 55;
int e[N][N], st[N * N], ed[N * N], n, m;
vector<int> seq[N * N];
pair<int, int> walk(vector<int> &vec, int x, int flg) {
  int p = 0;
  for (; p + 1 <= vec.size();) {
    int y = vec[p], ed = e[x][y];
    if (!ed || vec.size() > 2 * n || ((ed > m) ^ flg))
      return pair<int, int>(23333, -1);
    for (auto j : seq[ed]) vec.push_back(j);
    x = y;
    ++p;
  }
  return pair<int, int>(vec.size(), x);
}
void work(bool flg) {
  for (int i = (int)(1); i <= (int)(2 * m); i++)
    if ((i <= m) ^ flg)
      for (int j = (int)(0); j <= (int)(seq[i].size() - 2); j++)
        if (seq[i][j] == st[i] && seq[i][j + 1] == ed[i]) {
          int sz = seq[i].size();
          vector<int> t1, t2;
          for (int k = (int)(j - 1); k >= (int)(0); k--)
            t1.push_back(seq[i][k]);
          for (int k = (int)(j + 2); k <= (int)(sz - 1); k++)
            t2.push_back(seq[i][k]);
          pair<int, int> res1 = walk(t1, st[i], flg ^ 1);
          pair<int, int> res2 = walk(t2, ed[i], flg);
          if (res1.first + res2.first + 2 <= 2 * n) {
            vector<int> ans;
            reverse(t1.begin(), t1.end());
            for (auto i : t1) ans.push_back(i);
            ans.push_back(st[i]);
            ans.push_back(ed[i]);
            for (auto i : t2) ans.push_back(i);
            if (flg) reverse(ans.begin(), ans.end());
            printf("%d\n", ans.size());
            for (auto i : ans) printf("%d ", i);
            exit(0);
          }
        }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (int)(1); i <= (int)(m); i++) {
    int x, y, cnt, v;
    scanf("%d%d%d", &x, &y, &cnt);
    e[x][y] = i;
    e[y][x] = i + m;
    st[i] = ed[i + m] = x;
    ed[i] = st[i + m] = y;
    for (int j = (int)(1); j <= (int)(cnt); j++) {
      scanf("%d", &v);
      seq[i].push_back(v);
    }
    seq[i + m] = seq[i];
    reverse(seq[i + m].begin(), seq[i + m].end());
  }
  work(0);
  work(1);
  puts("1");
}

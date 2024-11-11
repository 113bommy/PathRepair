#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int n, s, e, x[5010], a[5010], b[5010], c[5010], d[5010];
long long len[5010][5010], ans;
vector<int> vec;
int main() {
  scanf("%d%d%d", &n, &s, &e);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (j < i)
        len[i][j] = (long long)abs(x[i] - x[j]) + c[i] + b[j];
      else
        len[i][j] = (long long)abs(x[i] - x[j]) + d[i] + a[j];
    }
  vec.push_back(s);
  vec.push_back(e);
  ans = len[s][e];
  for (int i = 1; i <= n; i++) {
    if (i == s && i == e) continue;
    int pos = 1;
    long long temp =
        ans - len[vec[0]][vec[1]] + len[vec[0]][i] + len[i][vec[1]];
    for (int j = 2; j < vec.size(); j++) {
      long long tp =
          ans - len[vec[j - 1]][vec[j]] + len[vec[j - 1]][i] + len[i][vec[j]];
      if (tp < temp) pos = j, temp = tp;
    }
    ans = ans - len[vec[pos - 1]][vec[pos]] + len[vec[pos - 1]][i] +
          len[i][vec[pos]];
    vec.insert(vec.begin() + pos, i);
  }
  cout << ans << endl;
  return 0;
}

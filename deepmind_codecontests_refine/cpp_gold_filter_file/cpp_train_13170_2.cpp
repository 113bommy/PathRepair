#include <bits/stdc++.h>
using namespace std;
const double g = 10.0, eps = 1e-9;
const int N = 3000 + 10, maxn = 2000 + 10, inf = 0x3f3f3f3f,
          INF = 0x3f3f3f3f3f3f3f3f;
const unsigned long long bs = 163;
char s[N], p[N];
unsigned long long Hash[N][N];
int ssz, psz;
vector<pair<int, int> > v;
void init() {
  for (int i = 1; i <= ssz; i++) {
    Hash[i][i] = s[i] - 'a';
    for (int j = i + 1; j <= ssz; j++)
      Hash[i][j] = Hash[i][j - 1] * bs + s[j] - 'a';
    for (int j = i - 1; j >= 1; j--)
      Hash[i][j] = Hash[i][j + 1] * bs + s[j] - 'a';
  }
}
pair<int, int> solve(unsigned long long x, int dis) {
  for (int i = 1; i + dis <= ssz; i++)
    if (Hash[i][i + dis] == x) return make_pair(i, i + dis);
  for (int i = dis + 1; i <= ssz; i++)
    if (Hash[i][i - dis] == x) return make_pair(i, i - dis);
  return make_pair(-1, -1);
}
int main() {
  scanf("%s%s", s + 1, p + 1);
  ssz = strlen(s + 1), psz = strlen(p + 1);
  init();
  unsigned long long te = 0;
  int ans = 0, last = 0;
  for (int i = 1; i <= psz; i++) {
    te = te * bs + p[i] - 'a';
    if (i - 1 == last && solve(te, 0).first == -1) return 0 * puts("-1");
    if (i + 1 <= psz && solve(te * bs + p[i + 1] - 'a', i - last).first == -1) {
      v.push_back(solve(te, i - last - 1));
      te = 0, last = i;
    }
  }
  if (solve(te, psz - last - 1).first == -1)
    return 0 * puts("-1");
  else
    v.push_back(solve(te, psz - last - 1));
  printf("%d\n", v.size());
  for (int i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 310000;
int n, m, K, num, q[N], sz, col[N], tot;
bool ch[N];
vector<int> v[N];
map<int, bool> b[N];
void Find(int x) {
  col[x] = num;
  int s2 = 0;
  for (int i = 1; i <= sz; i++)
    if (!b[x][q[i]])
      v[x].push_back(q[i]);
    else
      q[++s2] = q[i];
  sz = s2;
  for (int i = 1; i <= v[x].size(); i++) Find(v[x][i - 1]);
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    b[x][y] = b[y][x] = 1;
  }
  for (int i = 2; i <= n; i++) q[++sz] = i;
  while (sz) {
    num++, sz--, Find(q[sz + 1]);
  }
  for (int i = 2; i <= n; i++) {
    if (!b[1][i]) ch[col[i]] = 1, tot++;
  }
  bool fl = (num <= K) & (K <= tot);
  for (int i = 1; i <= num; i++) fl &= ch[i];
  puts(fl ? "possible" : "impossible");
  return 0;
}

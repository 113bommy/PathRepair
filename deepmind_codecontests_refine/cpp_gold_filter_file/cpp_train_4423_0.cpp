#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long INF = ~0ULL >> 1;
template <class T>
inline void read(T &n) {
  char c;
  for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar())
    ;
  n = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int Pow(int base, int n, int mo) {
  if (n == 0) return 1;
  if (n == 1) return base % mo;
  int tmp = Pow(base, n >> 1, mo);
  tmp = (long long)tmp * tmp % mo;
  if (n & 1) tmp = (long long)tmp * base % mo;
  return tmp;
}
int e[1200][1200], x, y, N;
vector<pair<pair<int, int>, pair<int, int> > > ret;
vector<pair<int, int> > ans;
set<int> E[1200];
void checkmin(int &x, int &y) {
  if (x > y) swap(x, y);
}
inline int c(int x, int y) {
  if (e[x][y]) return 1;
  return abs(x - y) == 1 || x == 1 && y == N || x == N && y == 1;
}
void flip(int x, int y) {
  int a = 0, b = 0;
  for (int i = (1); i <= (N); ++i)
    if ((c(i, x) || c(x, i)) && (c(i, y) || c(y, i))) {
      if (!a)
        a = i;
      else
        b = i;
    }
  ret.push_back((make_pair((make_pair(x, y)), (make_pair(a, b)))));
  e[x][y] = 0;
  E[x].erase(y);
  e[a][b] = 1;
  E[a].insert(b);
}
void solve(int l, int r) {
  if (r - l < 2) return;
  int m = l + r >> 1;
  for (int i = (l); i <= (m - 1); ++i) {
    for (set<int>::iterator j = E[i].upper_bound(m); j != E[i].end();
         j = E[i].upper_bound(m))
      flip(i, *j);
  }
  solve(l, m);
  solve(m, r);
}
int main() {
  scanf("%d", &N);
  for (int i = (1); i <= (N); ++i) E[i].clear();
  for (int i = (1); i <= (N - 3); ++i)
    scanf("%d%d", &x, &y), checkmin(x, y), e[x][y] = 1, E[x].insert(y);
  solve(2, N);
  for (int i = (0); i < (ret.size()); ++i) ans.push_back(ret[i].first);
  memset(e, 0, sizeof(e));
  ret.clear();
  for (int i = (1); i <= (N); ++i) E[i].clear();
  for (int i = (1); i <= (N - 3); ++i)
    scanf("%d%d", &x, &y), checkmin(x, y), e[x][y] = 1, E[x].insert(y);
  solve(2, N);
  reverse(ret.begin(), ret.end());
  for (int i = (0); i < (ret.size()); ++i) ans.push_back(ret[i].second);
  printf("%d\n", ans.size());
  for (int i = (0); i < (ans.size()); ++i)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}

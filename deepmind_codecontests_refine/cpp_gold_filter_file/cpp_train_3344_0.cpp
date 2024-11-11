#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
const int MAXQ = 100010;
const double EPS = 1e-8;
const double DINF = 1e30;
const int IINF = ~0U >> 3;
const long long LINF = 1LL << 61;
void debug() { cout << "error_here" << endl; }
int n, m, d[MAXN];
int p[MAXN], w[MAXN];
vector<pair<pair<int, int>, int> > ans;
void init() {
  scanf("%d%d", &n, &m);
  memset(p, -1, sizeof(p));
  memset(d, 0, sizeof(d));
  memset(w, 127, sizeof(w));
  for (int i = 0, a; i < m; ++i) {
    scanf("%d", &a);
    scanf("%d%d", &p[a], &w[a]);
    d[p[a]]++;
  }
  for (int i = 1; i <= n; ++i)
    if (!d[i] && ~p[i]) {
      int start = i, end, u = w[i];
      for (int j = i; ~j; j = p[j]) d[j]++, end = j, u = min(u, w[j]);
      ans.push_back(make_pair(make_pair(start, end), u));
    }
  printf("%d\n", ans.size());
  for (int i = 0; i < (int)ans.size(); ++i)
    printf("%d %d %d\n", ans[i].first.first, ans[i].first.second,
           ans[i].second);
}
int main() {
  init();
  return 0;
}

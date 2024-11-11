#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
template <class T>
void mini(T &l, T r) {
  l = min(l, r);
}
template <class T>
void maxi(T &l, T r) {
  l = max(l, r);
}
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, a...);
}
template <class T>
ostream &operator<<(ostream &os, vector<T> v) {
  os << "[";
  for (auto vv : v) os << vv << ",";
  return os << "]";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> p) {
  return os << "(" << p.first << "," << p.second << ")";
}
const int N = 60;
int n, m, k;
int a[N][N];
vector<pair<int, int> > go(pair<int, int> p) {
  int x = p.first, y = p.second;
  vector<pair<int, int> > ret;
  for (int i = 1; i <= x; ++i) {
    ret.push_back(make_pair(i, 1));
  }
  for (int i = 2; i <= y; ++i) {
    ret.push_back(make_pair(x, i));
  }
  return ret;
}
void print(vector<pair<int, int> > p) {
  for (int i = 0; i < p.size(); ++i) {
    printf("(%d,%d)%c", p[i].first, p[i].second, " \n"[i == (int)p.size() - 1]);
  }
}
void run() {
  scanf("%d%d%d", &n, &m, &k);
  vector<pair<int, pair<int, int> > > v;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      a[i][j] = i + j - 1 - 1;
      v.push_back(make_pair(a[i][j], make_pair(i, j)));
    }
  }
  sort(v.begin(), v.end());
  v.erase(v.begin() + k, v.end());
  reverse(v.begin(), v.end());
  ;
  int ans = 0;
  vector<vector<pair<int, int> > > path(k);
  for (int i = 0; i < k; ++i) {
    path[i] = go(v[i].second);
    ans += path[i].size();
  }
  printf("%d\n", ans);
  for (auto pth : path) {
    print(pth);
  }
}
int main() {
  run();
  return 0;
}

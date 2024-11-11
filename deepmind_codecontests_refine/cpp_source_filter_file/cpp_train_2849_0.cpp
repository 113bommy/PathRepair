#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
map<string, int> idx;
class DSet {
 public:
  static const int SIZE = 10010;
  int sz[SIZE], p[SIZE];
  void init(int n) {
    for (int i = 0; i < n; i += sz[p[i] = i] = 1)
      ;
  }
  int root(int x) { return p[x] != x ? p[x] = root(p[x]) : x; }
  bool join(int x, int y) {
    x = root(x), y = root(y);
    if (x == y) return false;
    if (sz[x] <= sz[y])
      sz[p[x] = y] += sz[x];
    else
      sz[p[y] = x] += sz[y];
    return true;
  }
} ds;
int getidx(const string& s) {
  auto t = idx.find(s);
  if (t == idx.end()) t = idx.insert(make_pair(s, idx.size())).first;
  return t->second;
}
vector<int> e[10005];
string s[10005];
bitset<10005> a[10005];
unordered_map<int, int> c[10005];
int main() {
  int m, x, y;
  scanf("%d", &m);
  ds.init(10005);
  for (int i = 0; i < m; i++) {
    char s[105];
    scanf("%s", s);
    x = getidx(s);
    scanf("%s", s);
    y = getidx(s);
    e[x].push_back(y);
    e[y].push_back(x);
    a[x].set(y);
    a[y].set(x);
    ds.join(x, y);
  }
  for (auto& r : idx) s[r.second] = r.first;
  int n = idx.size();
  printf("%d\n", n);
  for (int i = 0; i < n; i++) a[i].set(i) = 1;
  for (int i = 0; i < n; i++) {
    for (size_t j = 0; j < e[i].size(); j++)
      for (size_t k = j + 1; k < e[i].size(); k++) {
        int x = e[i][j], y = e[i][k];
        if (!a[x].test(y)) {
          c[x][y]++;
          c[y][x]++;
        }
      }
  }
  for (int i = 0; i < n; i++) {
    int top = 0, cnt = 0;
    for (auto& r : c[i]) {
      if (top < r.second)
        cnt = 1, top = r.second;
      else if (top == r.second)
        cnt++;
    }
    if (!top) cnt = n - ds.sz[ds.root(i)];
    printf("%s %d\n", s[i].c_str(), cnt);
  }
}

#include <bits/stdc++.h>
using namespace std;
const int MAX = 2510;
const long long mod = 10003;
const int seed = 2333;
long long treesum[MAX][MAX];
int n, m, q;
map<tuple<int, int, int, int>, int> mp;
inline int lowbit(int x) { return (x) & (-x); }
void update(int x, int y, long long c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    for (int j = y; j <= m; j += lowbit(j)) {
      treesum[i][j] += c;
    }
  }
}
long long query(int x, int y) {
  long long ret = 0;
  for (int i = x; i; i -= lowbit(i)) {
    for (int j = y; j; j -= lowbit(j)) {
      ret += treesum[i][j];
    }
  }
  return ret;
}
inline int hhash(int x1, int y1, int x2, int y2) {
  int ret = x1;
  ret = (1LL * ret * seed % mod + y1) % mod;
  ret = (1LL * ret * seed % mod + x2) % mod;
  ret = (1LL * ret * seed % mod + y2) % mod;
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  while (q--) {
    int t, x1, y1, x2, y2;
    scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
    if (t == 1) {
      int t = mp[make_tuple(x1, y1, x2, y2)] = hhash(x1, y1, x2, y2);
      update(x2 + 1, y2 + 1, t);
      update(x2 + 1, y1, -t);
      update(x1, y2 + 1, -t);
      update(x1, y1, t);
    } else if (t == 2) {
      int t = mp[make_tuple(x1, y1, x2, y2)];
      update(x2 + 1, y2 + 1, -t);
      update(x2 + 1, y1, t);
      update(x1, y2 + 1, t);
      update(x1, y1, -t);
    } else {
      if (query(x1, y1) == query(x2, y2)) {
        puts("Yes");
      } else {
        puts("No");
      }
    }
  }
}

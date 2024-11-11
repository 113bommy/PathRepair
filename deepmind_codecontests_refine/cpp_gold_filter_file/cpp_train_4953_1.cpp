#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int mods = 1e9 + 7;
const int MAXN = 1000005;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
vector<pair<int, int> > Ans;
int flag[1005][1005];
signed main() {
  int n = read(), k = read();
  if (k != 2 && k != 3) {
    puts("-1");
    return 0;
  }
  if (k == 2) {
    if (n <= 4) {
      puts("-1");
      return 0;
    }
    Ans.push_back(make_pair(1, 2)), Ans.push_back(make_pair(1, 3)),
        Ans.push_back(make_pair(1, 4));
    Ans.push_back(make_pair(2, 3)), Ans.push_back(make_pair(2, 5));
    Ans.push_back(make_pair(4, 5));
    for (int i = 6, lst = 2; i <= n; lst = i, i++)
      for (int j = 1; j < i; j++)
        if (j != lst) Ans.push_back(make_pair(i, j));
  }
  if (k == 3) {
    if (n <= 3) {
      puts("-1");
      return 0;
    }
    for (int i = 1; i <= n - 1; i++)
      for (int j = i + 1; j <= n - 1; j++)
        if (i != 1 || j != 2) Ans.push_back(make_pair(i, j));
    Ans.push_back(make_pair(1, n));
  }
  printf("%d\n", Ans.size());
  for (auto v : Ans) printf("%d %d\n", v.first, v.second);
  return 0;
}

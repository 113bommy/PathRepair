#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void Qmin(T &a, const T b) {
  if (b < a) a = b;
}
template <class T>
inline void Qmax(T &a, const T b) {
  if (a < b) a = b;
}
inline int Qceil(int x, int y) { return x ? (x - 1) / y + 1 : 0; }
const int inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3fLL;
const double pi = acos(-1.0);
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
typedef set<int>::iterator siter;
typedef map<int, int>::iterator miter;
typedef priority_queue<int> pqi;
typedef priority_queue<int, vector<int>, greater<int> > spqi;
typedef pair<int, int> p2;
inline bool okC(char &c) { return c = getchar(), c != 10 && ~c; }
inline bool okS(char *s) { return s = gets(s), s && *s; }
int cas;
const int mx = int(1e5) + 5;
vector<int> tmp, ans;
bool vis[mx];
int main() {
  int n, m, i, j;
  scanf("%d", &n);
  m = n >> 1;
  for (i = 3; i < (m + 1); ++i) {
    tmp.clear();
    for (j = i; j < (n + 1); j += (i))
      if (!vis[j]) tmp.push_back(j);
    if (tmp.size() & 1) {
      if (tmp.size() == 1) continue;
      ans.push_back(tmp[0]), ans.push_back(tmp[2]),
          vis[tmp[0]] = vis[tmp[2]] = true;
      for (j = 3; j < (tmp.size()); ++j)
        ans.push_back(tmp[j]), vis[tmp[j]] = true;
    } else if (!tmp.empty()) {
      for (j = 0; j < (tmp.size()); ++j)
        ans.push_back(tmp[j]), vis[tmp[j]] = true;
    }
  }
  for (i = 2; i < (n + 1); i += (2))
    if (!vis[i]) ans.push_back(i);
  printf("%d\n", ans.size() >> 1);
  for (i = 0; i < (ans.size()); i += (2)) printf("%d %d\n", ans[i], ans[i + 1]);
  return 0;
}

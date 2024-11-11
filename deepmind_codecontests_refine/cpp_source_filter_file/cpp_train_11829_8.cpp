#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
bool pd[N];
int n, m, cnt, h[N], p[N];
struct Edge {
  int to, nxt;
  Edge(int V = 0, int N = 0) : to(V), nxt(N) {}
} e[N << 1];
struct nod {
  int x, y, z;
};
vector<nod> ans;
inline bool isdigit(const char &ch) { return (ch >= '0' && ch <= '9'); }
inline int read() {
  register int s = 0;
  register bool m = false;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') m = true;
    ch = getchar();
  }
  while (isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return m ? -s : s;
}
inline void _SOL(const int &u) {
  pd[u] = true;
  for (register int i = h[u]; i; i = e[i].nxt) {
    register int v = e[i].to;
    e[i].to = e[i ^ 1].to = 0;
    if (v) {
      if (!pd[v]) _SOL(v);
      if (p[v])
        ans.push_back((nod){u, v, p[v]}), p[v] = 0;
      else if (p[u])
        ans.push_back((nod){v, u, p[u]}), p[u] = 0;
      else
        p[u] = v;
    }
  }
}
signed main(int _lzh, char const *__lzh[]) {
  n = read(), m = read();
  for (register int i = 1; i <= m; ++i) {
    register int u = read(), v = read();
    e[++cnt] = Edge(v, h[u]), h[u] = cnt;
    e[++cnt] = Edge(u, h[v]), h[v] = cnt;
  }
  for (register int i = 1; i <= n; ++i)
    if (!pd[i]) _SOL(i);
  cout << ans.size() << endl;
  for (register int i = 0; i < ans.size(); ++i)
    cout << ans[i].x << " " << ans[i].y << " " << ans[i].z << endl;
  return 0;
}

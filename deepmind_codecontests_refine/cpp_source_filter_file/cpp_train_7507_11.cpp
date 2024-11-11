#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60000000")
using namespace std;
struct corpus {
  int tin, tind, tout, toutd;
  corpus() {
    tin = 0;
    tout = 0;
  }
};
struct rez {
  int fl, s, f;
};
int n, p, a, b, d;
vector<corpus> g;
vector<rez> ans;
bool cmp(const rez &a, const rez &b) { return a.fl > b.fl; }
int main() {
  cin >> n >> p;
  g.resize(n + 1);
  for (int i = 1; i <= p; i++) {
    cin >> a >> b >> d;
    g[a].tout = b;
    g[a].toutd = d;
    g[b].tin = a;
    g[b].tind = d;
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].tin == 0) {
      if (g[i].tout != 0) {
        int v = i;
        int push = g[i].toutd;
        do {
          push = min(push, g[v].toutd);
          v = g[v].tout;
        } while (g[v].tout != 0);
        rez r;
        r.fl = push;
        r.s = i;
        r.f = v;
        ans.push_back(r);
      }
    }
  }
  sort(ans.begin(), ans.end(), cmp);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].s << " " << ans[i].f << " " << ans[i].fl << endl;
  }
  return 0;
}

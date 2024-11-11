#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int inf = 1 << 28;
int in() {
  int x;
  scanf("%d", &x);
  return x;
}
long long In() {
  long long x;
  cin >> x;
  return x;
}
double inreal() {
  double x;
  scanf("%lf", &x);
  return x;
}
string instr() {
  char buf[1001];
  scanf("%s", buf);
  return (string)buf;
}
vector<int> G[1000111];
bool vis[1000111];
int dfs(int u) {
  vis[u] = 1;
  int res = 1;
  for (int i = 0; i < G[u].size(); i++)
    if (vis[G[u][i]] == 0) {
      res += dfs(G[u][i]);
    }
  return res;
}
int main() {
  int i, j;
  int n = in(), m = in(), k = in(), t;
  int u, v;
  for ((i) = (0); (i) < (int)(m); (i)++) {
    u = in() - 1, v = in() - 1;
    G[u].push_back(v), G[v].push_back(u);
  }
  multiset<int> snd;
  for ((i) = (0); (i) < (int)(n); (i)++)
    if (!vis[i]) snd.insert(min(k, dfs(i)));
  if (snd.size() <= 2) {
    puts("0");
    return 0;
  }
  multiset<int>::iterator it, et;
  int res = 0;
  for (bool update = 1; update;) {
    update = 0;
    it = snd.begin();
    et = snd.end();
    et--;
    if (*it == 1 and *et > 1) {
      snd.erase(it);
      t = *et - 1;
      snd.erase(et);
      snd.insert(t);
      update = 1;
      continue;
    }
    if (snd.size() <= 2) break;
    et = snd.end();
    et--;
    if (*et == 1) {
      snd.erase(snd.begin());
      snd.erase(et);
      snd.insert(min(2, k));
      res++;
      update = 1;
    }
  }
  cout << res << endl;
  return 0;
}

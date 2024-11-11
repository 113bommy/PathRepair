#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
const long long int INF = 2e9;
struct edge {
  int to;
  long long int gcd, lcm;
  edge() {}
  edge(int to, long long int gcd, long long int lcm)
      : to(to), gcd(gcd), lcm(lcm){};
};
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return a / gcd(a, b) * b;
}
long long int used[2000];
vector<edge> g[2000];
vector<int> path;
bool dfs(int id) {
  path.push_back(id);
  long long int mine = used[id];
  for (int i = 0; i < ((int)g[id].size()); i++) {
    int to = g[id][i].to;
    long long int gc = g[id][i].gcd;
    long long int lc = g[id][i].lcm;
    long long int q = lc * gc;
    if (q % mine) return false;
    long long int with = q / mine;
    if (gcd(with, mine) != gc || lcm(with, mine) != lc) return false;
    if (used[to] != -1) {
      if (with != used[to]) return false;
    } else {
      used[to] = with;
      if (!dfs(to)) return false;
    }
  }
  return true;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < (m); i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    a--;
    b--;
    g[a].push_back(edge(b, c, d));
    g[b].push_back(edge(a, c, d));
  }
  memset(used, -1, sizeof used);
  for (int i = 0; i < (n); i++) {
    if (used[i] == -1) {
      path.clear();
      long long int hi = 1;
      for (int j = 0; j < ((int)(g[i]).size()); j++) {
        hi = lcm(hi, g[i][j].gcd);
      }
      bool yes = false;
      for (int j = 1; j < 101; j++) {
        path.clear();
        used[i] = hi * j;
        if (dfs(i)) {
          yes = true;
          break;
        }
        for (int k = 0; k < ((int)(path).size()); k++) {
          used[path[k]] = -1;
        }
      }
      if (!yes) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < (n); i++) {
    printf("%I64d ", used[i]);
  }
}

#include <bits/stdc++.h>
using namespace std;
template <typename T>
T abs(T x) {
  return x > 0 ? x : -x;
}
const int maxn = 100005;
const long long ub = 314000000;
long long mi[maxn], ma[maxn];
long long prodMi[maxn], prodMa[maxn];
int inf[maxn];
int color[maxn];
vector<int> prod[maxn];
int prodDeg[maxn];
long long prodCost[maxn];
int prodM[maxn];
vector<int> prodByMonster[maxn];
vector<int> monsterInProd[maxn];
void calcProd(int v);
void dfs(int monster) {
  color[monster] = 1;
  for (int p : prodByMonster[monster]) {
    calcProd(p);
    if (prodDeg[p] > 0) continue;
    if (prodMa[p] == -2) {
      ma[monster] = -2;
      break;
    } else {
      ma[monster] = max(ma[monster], prodMa[p]);
    }
  }
  color[monster] = 2;
}
void calcProd(int v) {
  if (prodDeg[v] > 0) return;
  prodMa[v] = prodCost[v];
  for (int to : prod[v]) {
    if (color[to] == 1) {
      prodMa[v] = -2;
      return;
    }
    if (color[to] == 0) dfs(to);
    if (ma[to] == -2) {
      prodMa[v] = -2;
      return;
    } else {
      prodMa[v] = min(ub, prodMa[v] + ma[to]);
    }
  }
}
void gen() {
  freopen("a.in", "w", stdout);
  cout << 64 << " " << 32 << endl;
  for (int i = 1; i < 32; i++) {
    cout << i << " " << 3 << " " << i + 1 << " " << i + 1 << " " << -1 << endl;
    cout << i << " " << 2 << " "
         << " " << i + 1 << " " << -1 << endl;
  }
  cout << 32 << " " << 1 << " " << -1 << endl;
  cout << 32 << " " << 1 << " " << -1 << endl;
  exit(0);
}
int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d %d", &m, &n);
  for (int i = 0; i < m; i++) {
    int type, cnt;
    scanf("%d %d", &type, &cnt);
    prodByMonster[type].push_back(i);
    prodM[i] = type;
    for (int j = 0; j < cnt; j++) {
      int x;
      scanf("%d", &x);
      if (x == -1)
        prodCost[i]++;
      else {
        monsterInProd[x].push_back(i);
        prodDeg[i]++;
        prod[i].push_back(x);
      }
    }
    prodMi[i] = prodCost[i];
  }
  for (int i = 1; i <= n; i++) mi[i] = -1;
  priority_queue<pair<int, int> > q;
  for (int i = 0; i < m; i++) {
    if (prodDeg[i] == 0) {
      prodMi[i] = prodCost[i];
      int x = prodM[i];
      if (mi[x] == -1 || mi[x] > prodMi[i]) {
        mi[x] = prodMi[i];
        q.push(make_pair(-mi[x], x));
      }
    }
  }
  vector<int> used(n + 1, 0);
  while (!q.empty()) {
    int v = q.top().second;
    long long currD = -q.top().first;
    q.pop();
    if (currD != mi[v]) continue;
    for (int to : monsterInProd[v]) {
      if (!used[v]) {
        prodDeg[to] -= 1;
        ;
        prodMi[to] += currD;
        prodMi[to] = min(prodMi[to], ub);
        if (prodDeg[to] == 0) {
          int x = prodM[to];
          if (mi[x] == -1 || mi[x] > prodMi[to]) {
            mi[x] = prodMi[to];
            q.push(make_pair(-mi[x], x));
          }
        }
      }
    }
    used[v] = 1;
  }
  for (int i = 1; i <= n; i++)
    if (color[i] == 0) dfs(i);
  for (int i = 1; i <= n; i++) {
    if (mi[i] == -1)
      printf("-1 -1\n");
    else
      printf("%d %d\n", int(mi[i]), int(ma[i]));
  }
  return 0;
}

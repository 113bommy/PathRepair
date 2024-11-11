#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 228;
const int MAXN = 1e3 + 8;
vector<int> g[MAXN];
bool ms[MAXN][MAXN];
bool used[MAXN];
int n;
int get(int x, int y) {
  cout << x + 1 << ' ' << y + 1 << endl;
  int answer;
  cin >> answer;
  if (answer == -1) exit(228);
  return answer - 1;
}
void dfs(int v, int w) {
  if (v == w) return;
  used[v] = 1;
  for (auto to : g[v]) {
    if (!used[to]) {
      dfs(to, w);
    }
  }
}
int id1 = 0, id2 = 0;
pair<int, int> find_2() {
  for (; id1 < n; id1++) {
    if (used[id1]) continue;
    for (; id2 < n; id2++) {
      if (used[id2]) continue;
      if (ms[id1][id2]) continue;
      id2++;
      return {id1, id2 - 1};
    }
    id2 = 0;
  }
  return {-1, -1};
}
void ans(int x) {
  cout << "! " << x + 1 << endl;
  exit(0);
}
signed main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ms[i][i] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    int aa, bb;
    cin >> aa >> bb;
    aa--;
    bb--;
    ms[aa][bb] = ms[bb][aa] = 1;
    g[aa].push_back(bb);
    g[bb].push_back(aa);
  }
  int m = n;
  while (m > 2) {
    int x, y;
    tie(x, y) = find_2();
    if (x == -1) break;
    int w = get(x, y);
    dfs(x, w);
    dfs(y, w);
    m = 0;
    for (int i = 0; i < n; i++) {
      if (!used[i]) m++;
    }
  }
  int cnt = 0;
  int mn = 0;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      mn = i;
      cnt++;
    }
  }
  if (cnt == 1) {
    ans(mn);
  }
  int m2 = 0;
  for (int i = 0; i < n; i++) {
    if (used[i] || mn == i) continue;
    m2 = i;
  }
  ans(get(mn, m2));
  return 0;
}

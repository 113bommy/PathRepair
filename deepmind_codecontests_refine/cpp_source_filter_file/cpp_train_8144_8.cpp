#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n;
int edge[500000 + 20][2];
vector<int> v;
int belong[1500000], is[1500000], degree[1500000 + 2], vis[1000000 + 2],
    num[1000000 + 2];
vector<int> Can[1000000 + 1];
bool vvis[1000000 + 20];
vector<int> eech[1000000 + 20];
vector<pair<int, int> > g[1000000 + 20];
vector<int> ans;
void dfs(int now, int pre = -1) {
  while (g[now].size()) {
    pair<int, int> e = g[now].back();
    g[now].pop_back();
    if (vis[(e.second + 1) / 2]) {
      continue;
    }
    vis[(e.second + 1) / 2] = 1;
    dfs(e.first, e.second);
  }
  if (pre != -1) {
    ans.push_back(pre);
    int pp = pre;
    if (pp & 1) {
      pp++;
    } else {
      pp--;
    }
    ans.push_back(pp);
  }
}
void recover(int x) {
  memset(vis, 0, sizeof(vis));
  memset(is, 0, sizeof(is));
  memset(belong, 0, sizeof(belong));
  memset(degree, 0, sizeof(degree));
  int cnt = 0;
  int Index = 0;
  for (auto it : v) {
    Index++;
    int tail = (it & ((1 << x) - 1));
    if (!is[tail]) {
      is[tail] = ++cnt;
    }
    Can[is[tail]].push_back(Index);
    belong[it] = is[tail];
  }
  for (int i = 1; i <= n; ++i) {
    g[belong[edge[i][0]]].push_back(make_pair(belong[edge[i][1]], 2 * i - 1));
    g[belong[edge[i][1]]].push_back(make_pair(belong[edge[i][0]], 2 * i - 1));
  }
  dfs(2);
  for (auto it : ans) {
    cout << it << " ";
  }
}
void DDfs(int now) {
  vvis[now] = 1;
  for (auto it : eech[now]) {
    if (!vvis[it]) {
      DDfs(it);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> edge[i][0] >> edge[i][1], v.push_back(edge[i][0]),
        v.push_back(edge[i][1]), num[i * 2 - 1] = edge[i][0],
                                             num[i * 2] = edge[i][1];
  bool ok = 1;
  for (int id = 1; id <= 20; ++id) {
    memset(is, 0, sizeof(is));
    memset(belong, 0, sizeof(belong));
    memset(degree, 0, sizeof(degree));
    int cnt = 0;
    for (auto it : v) {
      int tail = (it & ((1 << id) - 1));
      if (!is[tail]) {
        is[tail] = ++cnt;
      }
      belong[it] = is[tail];
    }
    for (int i = 1; i <= n; ++i) {
      degree[belong[edge[i][0]]]++;
      eech[belong[edge[i][0]]].push_back(belong[edge[i][1]]);
      eech[belong[edge[i][1]]].push_back(belong[edge[i][0]]);
      degree[belong[edge[i][1]]]++;
    }
    for (int i = 1; i <= n; ++i) {
      if (degree[i] & 1) {
        cout << id - 1 << endl;
        ok = 0;
        recover(id - 1);
        break;
      }
    }
    if (!ok) break;
    memset(vvis, 0, sizeof(vvis));
    DDfs(1);
    for (int i = 1; i <= cnt; ++i) {
      if (!vvis[i]) {
        cout << id - 1 << endl;
        ok = 0;
        recover(id - 1);
        break;
      }
    }
    for (int i = 1; i <= cnt; ++i) eech[i].clear();
    if (!ok) break;
  }
  if (ok) {
    cout << 20 << endl;
    recover(20);
  }
  return 0;
}

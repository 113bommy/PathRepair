#include <bits/stdc++.h>
using namespace std;
int n1;
int n2;
int m;
int base1;
int base2;
int star;
int en;
map<int, int> mp;
vector<int> go[5002];
vector<int> rev[5002];
vector<int> cap[5002];
vector<int> id[5002];
void add(int a, int b, int c) {
  go[a].push_back(b);
  cap[a].push_back(c);
  rev[a].push_back(rev[b].size());
  go[b].push_back(a);
  cap[b].push_back(c);
  rev[b].push_back(rev[a].size() - 1);
  id[a].push_back(-1);
  id[b].push_back(-1);
}
bool use[5002];
inline bool dfs(int cur) {
  if (cur == en) {
    return true;
  }
  use[cur] = true;
  for (int i = 0; i < go[cur].size(); i++) {
    if (use[go[cur][i]]) continue;
    if (cap[cur][i] == 0) continue;
    if (dfs(go[cur][i]) == false) continue;
    cap[go[cur][i]][rev[cur][i]]++;
    cap[cur][i]--;
    return true;
  }
  return false;
}
void done() {
  while (1) {
    memset(use, false, sizeof(use));
    bool ok = dfs(star);
    if (ok) {
      continue;
    }
    break;
  }
}
map<pair<int, int>, int> ed;
vector<int> ans[5002];
int main() {
  cin >> n1 >> n2 >> m;
  star = 0;
  en = 1;
  base1 = 2;
  base2 = base1 + n1;
  for (int i = 0; i < n1; i++) {
    mp[base1 + i] = 0;
  }
  for (int i = 0; i < n2; i++) {
    mp[base2 + i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    a += base1;
    b += base2;
    mp[a]++;
    mp[b]++;
    add(a, b, 1);
    ed[make_pair(a - base1, b - base2)] = i + 1;
    id[a].back() = i + 1;
  }
  int mint = INT_MAX;
  for (auto it : mp) {
    mint = min(mint, it.second);
  }
  for (int i = 0; i < n1; i++) {
    add(star, base1 + i, mp[base1 + i] - mint);
  }
  for (int i = 0; i < n2; i++) {
    add(base2 + i, en, mp[base2 + i] - mint);
  }
  bool flag = true;
  int C = mint;
  int cur = -1;
  while (mint--) {
    cur++;
    if (flag == false) {
      for (int i = 0; i < go[star].size(); i++) {
        cap[star][i]++;
      }
      for (int i = 0; i < go[en].size(); i++) {
        cap[go[en][i]][rev[en][i]]++;
      }
    }
    done();
    flag = false;
    for (int i = 0; i < n1; i++) {
      int node = base1 + i;
      for (int j = 0; j < go[node].size(); j++) {
        if (cap[node][j] == 1 && go[node][j] != star) {
          ans[C - cur].push_back(id[node][j]);
        }
      }
    }
  }
  for (int i = 0; i <= C; i++) {
    cout << ans[i].size();
    for (int el : ans[i]) {
      printf(" %d", el);
    }
    puts("");
  }
  return 0;
}

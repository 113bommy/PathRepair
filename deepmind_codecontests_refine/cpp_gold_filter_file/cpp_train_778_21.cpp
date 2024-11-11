#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
long long int cnt;
long long int tas;
queue<int> q;
map<int, int> mp[6 * maxn + 10];
bool mark[6 * maxn + 10];
bool t;
bool k;
int n;
int m;
vector<int> v[6 * maxn + 10];
vector<pair<int, pair<int, pair<int, int>>>> p;
vector<int> addclause[6 * maxn + 10];
vector<int> rev[6 * maxn + 10];
vector<int> topol;
int cmp[6 * maxn + 10];
long long int ans[6 * maxn + 10];
long long int res[6 * maxn + 10];
int NOT(int val) {
  if (val < 3 * maxn) {
    return val + (3 * maxn);
  } else {
    return val - (3 * maxn);
  }
}
void pAq(int a, int b) {
  addclause[NOT(a)].push_back((b));
  addclause[NOT(b)].push_back((a));
  rev[(a)].push_back(NOT(b));
  rev[(b)].push_back(NOT(a));
}
void PQ(int a, int b) {
  addclause[NOT(a)].pop_back();
  addclause[NOT(b)].pop_back();
  rev[(a)].pop_back();
  rev[(b)].pop_back();
}
void sfd(int u, long long int tas) {
  mark[u] = true;
  cmp[u] = tas;
  for (int i = 0; i < rev[u].size(); i++) {
    if (mark[rev[u][i]] == false) {
      sfd(rev[u][i], tas);
    }
  }
}
void dfs(int u) {
  mark[u] = true;
  for (int i = 0; i < addclause[u].size(); i++) {
    if (mark[addclause[u][i]] == false) {
      dfs(addclause[u][i]);
    }
  }
  topol.push_back(u);
  return;
}
int check(int u) {
  tas = 0;
  vector<pair<int, int>> o;
  for (int i = 1; i <= m; i++) {
    if (p[i].second.second.second > u) {
      pAq(NOT(i), NOT(i));
      o.push_back({NOT(i), NOT(i)});
    }
  }
  memset(mark, 0, sizeof(mark));
  for (int i = 1; i <= 6 * maxn; i++) {
    if (mark[i] == false) {
      dfs(i);
    }
  }
  reverse(topol.begin(), topol.end());
  memset(mark, 0, sizeof(mark));
  for (int i = 0; i < 6 * maxn; i++) {
    if (mark[topol[i]] == false) {
      sfd(topol[i], tas++);
    }
  }
  topol.clear();
  int w = 0;
  for (int i = 1; i <= m; i++) {
    if (u == 1e9 + 1) {
    }
    if (cmp[i] == cmp[NOT(i)]) {
      w = 1;
    }
  }
  for (int i = 0; i < o.size(); i++) {
    int r = o[i].first;
    int e = o[i].second;
    PQ(r, e);
  }
  if (w == 1) {
    return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  p.push_back({0, {0, {0, 0}}});
  for (int i = 1; i <= m; i++) {
    int l;
    int r;
    int c;
    int t;
    cin >> l >> r >> c >> t;
    v[l].push_back(i);
    v[r].push_back(i);
    p.push_back({l, {r, {c, t}}});
    if (mp[l][c] == 0) {
      res[l]++;
      mp[l][c] = i;
    } else if (mp[l][c] != 1e9) {
      pAq(i, (mp[l][c]));
      pAq(NOT(i), NOT(mp[l][c]));
      mp[l][c] = 1e9;
    }
    if (mp[r][c] == 0) {
      res[r]++;
      mp[r][c] = i;
    } else if (mp[r][c] != 1e9) {
      pAq(i, (mp[r][c]));
      pAq(NOT(i), NOT(mp[r][c]));
      mp[r][c] = 1e9;
    }
    ans[l]++;
    ans[r]++;
  }
  cnt = m + 1;
  for (int i = 1; i <= n; i++) {
    if (ans[i] - res[i] > 1) {
      cout << "No";
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i] - res[i] == 0) {
      for (int j = 0; j < v[i].size(); j++) {
        if (j >= 1) {
          pAq(NOT(v[i][j]), NOT(j + cnt - 1));
          pAq(NOT(j + cnt - 1), j + cnt);
        }
        pAq(NOT(v[i][j]), j + cnt);
      }
      cnt += v[i].size();
    } else {
      for (int j = 0; j < v[i].size(); j++) {
        if (mp[i][p[v[i][j]].second.second.first] != 1e9) {
          pAq(NOT(v[i][j]), NOT(v[i][j]));
        }
      }
    }
  }
  int r = 1e9 + 1;
  int l = -1;
  while (l != r - 1) {
    int mid = (l + r) >> 1;
    if (check(mid) == 1) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (check(r) == 0) {
    cout << "No";
    return 0;
  }
  cout << "Yes" << endl;
  int u = 0;
  vector<int> op;
  for (int i = 1; i <= m; i++) {
    if (cmp[i] > cmp[NOT(i)]) {
      op.push_back(i);
      u = max(u, p[i].second.second.second);
    }
  }
  cout << u << " ";
  cout << op.size() << endl;
  for (int i = 0; i < op.size(); i++) {
    cout << op[i] << " ";
  }
  return 0;
}

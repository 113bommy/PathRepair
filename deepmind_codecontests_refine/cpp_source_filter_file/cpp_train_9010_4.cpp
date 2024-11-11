#include <bits/stdc++.h>
using namespace std;
const int max_n = 42, max_m = 11, max_q = 9, mod = 1000000007, max_log = 20,
          inf = 1011111111;
const long double eps = 1e-7;
int n, m, b, x[max_n][max_m * 2], cost[max_m], sum[2][max_n + max_m * 2], T,
    true_m, used1[max_m], used[max_n + max_m * 2], privet, ptr[max_m * 2];
vector<pair<pair<int, int>, pair<int, int> > > ans;
pair<int, int> p[max_n + max_m * 2];
vector<pair<int, int> > v[max_n + max_m * 2];
void get_T() {
  T = 0;
  for (int i = 0; i < n; ++i) {
    int sm = 0;
    for (int q = 0; q < m; ++q) {
      sm += x[i][q];
    }
    T = max(T, sm);
  }
  for (int i = 0; i < m; ++i) {
    int sm = 0;
    for (int q = 0; q < n; ++q) {
      sm += x[q][i];
    }
    T = max(T, sm);
  }
}
vector<int> is_exist() {
  vector<int> ans;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int sm = 0;
    for (int q = 0; q < m; ++q) {
      sm += x[i][q];
    }
    if (sm == T) return ans;
  }
  for (int q = 0; q < true_m; ++q)
    if (!used1[q]) {
      int sm = 0;
      for (int i = 0; i < n; ++i) {
        sm += x[i][q];
      }
      if (sm == T) {
        res += cost[q];
        ans.push_back(q);
      }
    }
  if (res <= b) {
    b -= res;
    for (int i = 0; i < ans.size(); ++i) {
      used[ans[i]] = 1;
    }
    return ans;
  }
  ans.clear();
  return ans;
}
void get_automates() {
  get_T();
  vector<int> adds = is_exist();
  while (adds.size()) {
    for (int i = 0; i < adds.size(); ++i) {
      int razn = sum[1][adds[i]];
      for (int q = v[adds[i]].size() - 1; razn >= v[adds[i]][q].second * 2;
           --q) {
        razn -= v[adds[i]].back().second * 2;
        v[m].push_back(v[adds[i]][q]);
        sum[1][adds[i]] -= v[m].back().second;
        sum[1][m] += v[m].back().second;
        swap(x[v[m].back().first][m], x[v[m].back().first][adds[i]]);
        v[adds[i]].pop_back();
      }
      if (razn > 1) {
        razn /= 2;
        v[m].push_back(make_pair(v[adds[i]].back().first, razn));
        v[adds[i]].back().second -= razn;
        sum[1][adds[i]] -= razn;
        sum[1][m] += razn;
        x[v[m].back().first][m] += razn;
        x[v[m].back().first][adds[i]] -= razn;
      }
      ptr[m] = adds[i];
      m++;
    }
    get_T();
    adds = is_exist();
  }
}
void add_graphs() {
  for (int i = 0; i < n; ++i) {
    if (sum[0][i] != T) {
      v[m + i].push_back(make_pair(i, T - sum[0][i]));
      sum[1][m + i] = T - sum[0][i];
      sum[0][i] = T;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (sum[1][i] != T) {
      v[i].push_back(make_pair(n + i, T - sum[1][i]));
      sum[0][n + i] = T - sum[1][i];
      sum[1][i] = T;
    }
  }
  int i, q;
  i = q = n + m - 1;
  while (i > n - 1 || q > m - 1) {
    if (sum[0][i] == T) {
      i--;
      continue;
    }
    if (sum[1][q] == T) {
      q--;
      continue;
    }
    int razn = T - max(sum[0][i], sum[1][q]);
    sum[0][i] += razn;
    sum[1][q] += razn;
    v[q].push_back(make_pair(i, razn));
  }
}
bool dfs(int x) {
  if (used[x]) return false;
  used[x] = 1;
  for (int i = 0; i < v[x].size(); ++i) {
    int to = v[x][i].first;
    if (p[to].first == -1 || dfs(p[to].first)) {
      p[to] = make_pair(x, i);
      return true;
    }
  }
  return false;
}
void get_pairs() {
  for (int i = 0; i < n + m; ++i) {
    p[i] = make_pair(-1, -1);
  }
  for (int i = 0; i < n + m; ++i) {
    memset(used, 0, sizeof(used));
    dfs(i);
  }
}
bool is_good() {
  for (int i = 0; i < n + m; ++i)
    if (v[i].size()) return true;
  return false;
}
void get_ans() {
  while (is_good()) {
    get_pairs();
    int mn = inf;
    for (int i = 0; i < n + m; ++i) {
      mn = min(mn, v[p[i].first][p[i].second].second);
    }
    for (int i = 0; i < n + m; ++i) {
      if (i < n && p[i].first < m) {
        ans.push_back(
            make_pair(make_pair(i, ptr[p[i].first]), make_pair(privet, mn)));
      }
      v[p[i].first][p[i].second].second -= mn;
      if (v[p[i].first][p[i].second].second == 0) {
        v[p[i].first].erase(v[p[i].first].begin() + p[i].second);
      }
    }
    privet += mn;
  }
}
int main() {
  cin >> n >> m >> b;
  true_m = m;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &cost[i]);
    ptr[i] = i;
  }
  for (int i = 0; i < n; ++i) {
    int k, y, g;
    scanf("%d", &k);
    for (int q = 0; q < k; ++q) {
      scanf("%d%d", &y, &g);
      y--;
      x[i][y] = g;
      v[y].push_back(make_pair(i, g));
      sum[0][i] += g;
      sum[1][y] += g;
    }
  }
  get_automates();
  add_graphs();
  get_ans();
  cout << privet << "\n";
  for (int i = 0; i < true_m; ++i) {
    if (used1[i]) {
      cout << "1";
    } else {
      cout << "0";
    }
  }
  cout << "\n" << ans.size() << "\n";
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i].first.first + 1 << " " << ans[i].first.second + 1 << " "
         << ans[i].second.first << " " << ans[i].second.second << "\n";
  }
}

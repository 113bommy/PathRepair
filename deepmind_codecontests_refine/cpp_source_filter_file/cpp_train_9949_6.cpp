#include <bits/stdc++.h>
using namespace std;
void solve(int test_number);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(9);
  cerr.setf(ios::fixed);
  cerr.precision(3);
  int n = 1;
  for (int i = 0; i < n; i++) {
    solve(i);
  }
}
const int MAX_N = 505;
const int MAX_M = MAX_N * 2;
const int SRC = MAX_M - 1;
const int DST = MAX_M - 2;
int n, precycle[MAX_N], cycle[MAX_N];
int bm[4];
int pos_len[MAX_N];
int mx_unknown_cycle;
int mx_known_cycle;
vector<int> dst[MAX_N];
vector<pair<int, int>> hypo;
vector<int> hypo_edge;
int im[MAX_M], rim[MAX_N], ans[MAX_N];
int f[MAX_M][MAX_M], c[MAX_M][MAX_M];
bool vis[MAX_M];
int dfs(int u) {
  if (u == DST) {
    return 1;
  }
  if (vis[u]) {
    return 0;
  }
  vis[u] = true;
  for (int i = 0; i < MAX_M; i++) {
    if (f[u][i] < c[u][i] && dfs(i)) {
      f[u][i]++;
      f[i][u]--;
      return 1;
    }
  }
  return 0;
}
bool match(pair<int, int> a, pair<int, int> b) {
  if (b.first >= 0 && b.first != a.first) {
    return false;
  }
  if (b.second >= 0 && b.second != a.second) {
    return false;
  }
  return true;
}
bool try_solve() {
  memset(c, 0, sizeof(c));
  memset(f, 0, sizeof(f));
  memset(im, -1, sizeof(im));
  memset(rim, -1, sizeof(rim));
  int dec = 0;
  for (int i = 0; i < hypo.size(); i++) {
    for (int j = 0; j < n; j++) {
      if (rim[j] >= 0) {
        continue;
      }
      if (hypo[i].first == precycle[j] && hypo[i].second == cycle[j]) {
        im[i] = j;
        rim[j] = i;
        dec++;
        break;
      }
    }
  }
  for (int i = 0; i < hypo.size(); i++) {
    for (int j = 0; j < n; j++) {
      if (match(hypo[i], make_pair(precycle[j], cycle[j]))) {
        if (rim[j] >= 0 || im[i] >= 0) {
          continue;
        }
        c[i + MAX_N][j] = 1;
      }
    }
  }
  for (int i = 0; i < hypo.size(); i++) {
    if (im[i] >= 0) {
      continue;
    }
    c[SRC][i + MAX_N] = 1;
  }
  for (int j = 0; j < n; j++) {
    if (rim[j] >= 0) {
      continue;
    }
    c[j][DST] = 1;
  }
  int flow = 0;
  do {
    memset(vis, false, sizeof(vis));
    if (!dfs(SRC)) {
      break;
    }
    flow++;
  } while (true);
  if (flow != hypo.size() - dec) {
    return false;
  }
  for (int i = 0; i < hypo.size(); i++) {
    for (int j = 0; j < n; j++) {
      if (f[i + MAX_N][j] == 1) {
        im[i] = j;
        rim[j] = i;
      }
    }
  }
  for (int i = 0; i < hypo.size(); i++) {
    ans[im[i]] = im[hypo_edge[i]];
  }
  for (int i = 0; i < n; i++) {
    if (rim[i] >= 0) {
      continue;
    }
    if (precycle[i] < 0 && cycle[i] < 0) {
      ans[i] = im[0];
    }
    if (precycle[i] < 0 && cycle[i] >= 0) {
      for (int j = 0; j < hypo.size(); j++) {
        if (hypo[j].second == cycle[i]) {
          ans[i] = im[j];
          break;
        }
      }
    }
    if (precycle[i] >= 0 && cycle[i] < 0) {
      if (precycle[i] == 0) {
        ans[i] = i;
      } else {
        for (int j = 0; j < hypo.size(); j++) {
          if (hypo[j].first == precycle[i] - 1) {
            ans[i] = im[j];
            break;
          }
        }
      }
    }
    if (precycle[i] >= 0 && cycle[i] >= 0) {
      if (precycle[i] == 0) {
        if (cycle[i] == 1) {
          ans[i] = i;
        } else {
          return false;
        }
      } else {
        for (int j = 0; j < hypo.size(); j++) {
          if (hypo[j].first == precycle[i] - 1 && hypo[j].second == cycle[i]) {
            ans[i] = im[j];
            break;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << " ";
  }
  cout << endl;
  return true;
}
void solve(int test_number) {
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  mx_known_cycle = mx_unknown_cycle = -1;
  for (int i = 0; i < n; i++) {
    string a;
    string b;
    cin >> a >> b;
    precycle[i] = cycle[i] = -1;
    if (a != "?") {
      istringstream ain(a);
      ain >> precycle[i];
    }
    if (b != "?") {
      istringstream bin(b);
      bin >> cycle[i];
      pos_len[cycle[i]] = 1;
    }
    if (precycle[i] >= 0 && cycle[i] < 0) {
      mx_unknown_cycle = max(mx_unknown_cycle, precycle[i]);
    }
    if (precycle[i] >= 0 && cycle[i] >= 0) {
      mx_known_cycle = max(mx_known_cycle, precycle[i]);
      dst[cycle[i]].push_back(precycle[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    sort(dst[i].begin(), dst[i].end());
  }
  for (int i = 1; i <= n; i++) {
    int cnt_z = count(dst[i].begin(), dst[i].end(), 0);
    int cnt_c = max((cnt_z + i - 1) / i, pos_len[i]);
    if (cnt_c == 0) {
      continue;
    }
    for (int j = 0; j < cnt_c; j++) {
      int f = hypo.size();
      for (int k = 0; k < i; k++) {
        hypo.push_back(make_pair(0, i));
        hypo_edge.push_back(f + (k + 1) % i);
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (dst[i].empty()) {
      continue;
    }
    vector<int> tmp = dst[i];
    tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
    int mx = dst[i][dst[i].size() - 1];
    mx_known_cycle = max(mx, mx_known_cycle);
    if (mx == 0) {
      continue;
    }
    int k;
    for (k = 0; k < hypo.size() && hypo[k].second != i; k++)
      ;
    for (int j = 1; j <= mx; j++) {
      hypo.push_back(make_pair(j, i));
      hypo_edge.push_back(k);
      k = hypo_edge.size() - 1;
    }
  }
  if (mx_known_cycle >= 0) {
    if (mx_unknown_cycle > mx_known_cycle) {
      for (int i = 1; i <= n; i++) {
        if (dst[i].empty() && !pos_len[i]) {
          continue;
        }
        vector<pair<int, int>> tmp_hypo = hypo;
        vector<int> tmp_hypo_edge = hypo_edge;
        int mx = (dst[i].empty()) ? 0 : dst[i][dst[i].size() - 1];
        int k;
        for (k = 0;
             k < hypo.size() && (hypo[k].first != mx || hypo[k].second != i);
             k++)
          ;
        for (int j = mx + 1; j <= mx_unknown_cycle; j++) {
          hypo.push_back(make_pair(j, hypo[k].second));
          hypo_edge.push_back(k);
          k = hypo_edge.size() - 1;
        }
        if (try_solve()) {
          return;
        }
        hypo = tmp_hypo;
        hypo_edge = tmp_hypo_edge;
      }
      cout << -1 << endl;
    } else if (!try_solve()) {
      cout << -1 << endl;
    }
  } else {
    if (hypo.empty()) {
      hypo.push_back(make_pair(0, 1));
      hypo_edge.push_back(0);
    }
    for (int j = 1; j <= mx_unknown_cycle; j++) {
      hypo.push_back(make_pair(j, 1));
      hypo_edge.push_back(hypo_edge.size());
    }
    if (!try_solve()) {
      cout << -1 << endl;
    }
  }
}

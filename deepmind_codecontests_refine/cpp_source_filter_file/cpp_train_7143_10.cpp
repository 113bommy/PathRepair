#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using s = int16_t;
vector<s> su[3000];
bool reach[3000][3000];
s step[3001][3001][12];
void dfs(int r, int f) {
  if (reach[f][r]) return;
  reach[f][r] = true;
  for (const auto &s : su[r]) dfs(s, f);
}
s go(s from, s to, int dis) {
  if (step[from][to][0] == 0) return 0;
  for (int i = 0; i < 12; i++) {
    if ((dis >> i) & 1) from = step[from][to][i];
  }
  return from;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    s a, b;
    cin >> a >> b;
    su[a].push_back(b);
  }
  for (int i = 1; i <= n; i++) {
    sort(begin(su[i]), end(su[i]));
    dfs(i, i);
  }
  for (int from = 1; from <= n; from++) {
    for (int to = 1; to <= n; to++) {
      for (const auto &via : su[from]) {
        if (reach[via][to]) {
          step[from][to][0] = via;
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    step[i][i][0] = 0;
  }
  for (int r = 0; r < 11; r++) {
    for (int from = 0; from < n + 1; from++) {
      for (int to = 0; to < n + 1; to++) {
        step[from][to][r + 1] = step[step[from][to][r]][to][r];
      }
    }
  }
  for (int i = 0; i < q; i++) {
    s from, to;
    int k;
    cin >> from >> to >> k;
    if (go(from, to, 3010) != 0) {
      cout << "-1\n";
      continue;
    }
    s it = go(from, to, k - 1);
    if (it == 0) it = -1;
    cout << it << '\n';
  }
}

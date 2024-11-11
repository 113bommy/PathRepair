#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  vector<vector<int> > edg(n);
  vector<bool> vis(n, false);
  vector<int> bipar(n, -1);
  vector<vector<int> > gr(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edg[a].push_back(b);
    edg[b].push_back(a);
  }
  if (!m) {
    long long int ans = (n) * (n - 1);
    ans /= 2;
    ans *= (n - 2);
    ans /= 3;
    cout << 3 << " " << ans;
  } else {
    int maxcount = 0, count = 0;
    int cyc = 0;
    for (int i = 0; i < n; i++) {
      count = 0;
      if (!vis[i]) {
        stack<int> dfs;
        dfs.push(i);
        gr[i].push_back(i);
        bipar[i] = 0;
        vis[i] = 1;
        while (!dfs.empty()) {
          count++;
          maxcount = max(maxcount, count);
          int tp = dfs.top();
          dfs.pop();
          for (int j = 0; j < edg[tp].size(); j++) {
            int v = edg[tp][j];
            if (vis[v]) {
              if (bipar[v] == bipar[tp]) {
                cyc++;
              }
            } else {
              bipar[v] = 1 - bipar[tp];
              gr[i].push_back(v);
              vis[v] = 1;
              dfs.push(v);
            }
          }
        }
      }
    }
    if (maxcount < 3) {
      cout << 2 << " " << m * (n - 2) << endl;
    } else {
      if (cyc) {
        cout << 0 << " " << cyc / 2 << endl;
      } else {
        long long int ans = 0;
        for (int i = 0; i < n; i++) {
          if (!gr[i].size()) continue;
          long long int a1, a2;
          a1 = 0;
          a2 = 0;
          for (int j = 0; j < gr[i].size(); j++) {
            int k = gr[i][j];
            if (bipar[k]) {
              a1++;
            } else {
              a2++;
            }
          }
          ans += (a1 * (a1 - 1)) / 2 + (a2 * (a2 - 1)) / 2;
        }
        cout << 1 << " " << ans << endl;
      }
    }
  }
  return 0;
}

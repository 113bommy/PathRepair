#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<long long> g[100100];
bool used[100100];
long long tot[100100];
long long tt = 0;
int sic = 0;
long long ww[100100];
void dfs(int v, int k) {
  tot[v] = k;
  used[v] = 1;
  tt++;
  for (int i = 0; i < g[v].size(); i++) {
    long long to = g[v][i];
    if (used[to]) {
      if ((k - tot[to]) >= 2 && (k - tot[to]) % 2 == 0) sic++;
    } else {
      dfs(to, k + 1);
    }
  }
}
long long b[3];
void dfs1(int v, int k) {
  b[k % 2]++;
  tot[v] = k;
  used[v] = 1;
  tt++;
  for (int i = 0; i < g[v].size(); i++) {
    long long to = g[v][i];
    if (!used[to]) {
      dfs1(to, k + 1);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  long long mm = 0;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      tt = 0;
      dfs(i, 0);
      ww[tt]++;
      mm = max(mm, tt);
    }
  }
  if (sic > 0) {
    cout << 0 << " " << sic << endl;
    return 0;
  }
  if (mm >= 3) {
    long long sol = 0;
    memset(used, 0, sizeof used);
    memset(tot, 0, sizeof tot);
    for (int i = 1; i <= n; i++) {
      if (!used[i]) {
        b[0] = 0;
        b[1] = 0;
        tt = 0;
        dfs1(i, 0);
        if (tt >= 3) {
          long long k = ((b[0] - 1) * b[0]) / 2;
          sol += k;
          k = ((b[1] - 1) * b[1]) / 2;
          sol += k;
        }
      }
    }
    cout << 1 << " " << sol << endl;
  } else if (mm == 2) {
    long long sol = 0;
    long long k = 2 * (ww[2] * (ww[2] - 1));
    sol = k;
    sol += (ww[2] * ww[1]);
    cout << 2 << " " << sol << endl;
  } else {
    long long sol = 1;
    if (n - 3 > 3) {
      for (int i = n - 2; i <= n; i++) {
        sol *= i;
      }
      sol /= (6);
    } else {
      for (int i = 4; i <= n; i++) {
        sol *= i;
      }
      long long k = 1;
      if (n - 3 != 0) {
        for (int i = 1; i <= n - 3; i++) {
          k *= i;
        }
      }
      sol /= k;
    }
    cout << 3 << " " << sol << endl;
  }
  return 0;
}

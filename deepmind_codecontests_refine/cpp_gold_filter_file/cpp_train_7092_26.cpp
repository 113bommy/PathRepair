#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256777216")
using namespace std;
int n, m;
vector<int> gr[100013];
vector<int> gr2[100013];
bool b[100013];
int val[100013];
vector<int> tmp;
void dfs(int v) {
  b[v] = true;
  tmp.push_back(v);
  for (int i = 0; i < gr[v].size(); i++) {
    if (!b[gr[v][i]]) {
      dfs(gr[v][i]);
    }
  }
}
void dfs2(int v) {
  b[v] = true;
  tmp.push_back(v);
  for (int i = 0; i < gr2[v].size(); i++) {
    if (!b[gr2[v][i]]) {
      dfs2(gr2[v][i]);
    }
  }
}
bool f(int w) {
  int t;
  while (w != 0) {
    t = w % 10;
    if (t != 7 && t != 4) return false;
    w /= 10;
  }
  return true;
}
int main() {
  cin >> n;
  int u, v, w;
  for (int i = 1; i < n; i++) {
    scanf("%d%d%d", &u, &v, &w);
    if (f(w)) {
      gr2[u].push_back(v);
      gr2[v].push_back(u);
    } else {
      gr[u].push_back(v);
      gr[v].push_back(u);
    }
  }
  memset(b, 0, sizeof(b));
  memset(val, 0, sizeof(val));
  for (int i = 1; i <= n; i++) {
    if (!b[i]) {
      tmp.clear();
      dfs(i);
      int t = tmp.size();
      for (int j = 0; j < t; j++) {
        val[tmp[j]] = t - 1;
      }
    }
  }
  memset(b, 0, sizeof(b));
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!b[i]) {
      tmp.clear();
      dfs2(i);
      long long k = tmp.size();
      long long t = 0;
      for (int i = 0; i < k; i++) {
        if (val[tmp[i]] > 0) {
          t++;
        }
      }
      for (int i = 0; i < k; i++) {
        if (val[tmp[i]] > 0) {
          ans += (n - val[tmp[i]] - 1ll) * (n - val[tmp[i]] - 2ll);
        }
      }
      ans += (k - t) * (n - 1) * (n - 2);
    }
  }
  cout << ans;
  return 0;
}

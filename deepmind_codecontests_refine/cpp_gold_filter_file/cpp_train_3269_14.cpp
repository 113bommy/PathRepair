#include <bits/stdc++.h>
using namespace std;
int p[1000000];
map<int, int> mp;
vector<vector<int> > adjlist;
int maxi = 0, hi;
void dfs(int s, int de, int pr) {
  if (maxi < de && mp[s]) {
    maxi = de;
    hi = s;
  }
  for (int i = 0; i < adjlist[s].size(); i++) {
    int v = adjlist[s][i];
    if (v != pr) dfs(v, de + 1, s);
  }
}
int depth1[1000000], depth2[1000000];
void d1(int s, int de, int pr) {
  depth1[s] = de;
  for (int i = 0; i < adjlist[s].size(); i++) {
    int v = adjlist[s][i];
    if (v != pr) d1(v, de + 1, s);
  }
}
void d2(int s, int de, int pr) {
  depth2[s] = de;
  for (int i = 0; i < adjlist[s].size(); i++) {
    int v = adjlist[s][i];
    if (v != pr) d2(v, de + 1, s);
  }
}
int main() {
  int n, m, d;
  cin >> n >> m >> d;
  adjlist.assign(n + 1, vector<int>());
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> p[i];
    mp[p[i]] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
  }
  dfs(1, 0, 1);
  int f1 = hi;
  maxi = 0;
  dfs(hi, 0, hi);
  int f2 = hi;
  d1(f1, 0, f1);
  d2(f2, 0, f2);
  int coun = 0;
  for (int i = 1; i <= n; i++) {
    if (depth1[i] <= d && depth2[i] <= d) {
      coun++;
    }
  }
  cout << coun;
  return 0;
}

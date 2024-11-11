#include <bits/stdc++.h>
using namespace std;
const int MAXN = 207;
const int MOD = 1000000007;
int n;
int c[MAXN];
int deg[MAXN];
vector<int> G[MAXN];
void p1() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    c[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> deg[i];
    for (int j = 0; j < deg[i]; j++) {
      int a;
      cin >> a;
      a--;
      G[a].push_back(i);
    }
  }
  int r = 100000000;
  for (int st = 0; st < 3; st++) {
    int times = 0;
    queue<int> Q[3];
    vector<int> ind(deg, deg + n);
    for (int i = 0; i < n; i++)
      if (deg[i] == 0) Q[c[i]].push(i);
    int hs = st;
    while (!Q[0].empty() || !Q[1].empty() || !Q[2].empty()) {
      if (Q[hs].empty()) {
        times++;
        hs = (hs + 1) % 3;
        continue;
      }
      int p = Q[hs].front();
      Q[hs].pop();
      times++;
      for (int i = 0; i < G[p].size(); i++) {
        int q = G[p][i];
        if (--ind[q] == 0) Q[c[q]].push(q);
      }
    }
    r = min(r, times);
  }
  cout << r << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  p1();
  return 0;
}

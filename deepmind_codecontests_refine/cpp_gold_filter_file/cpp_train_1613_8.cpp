#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
int stp[3005][3005];
vector<int> vc[3005];
int n, m, s1, t1, l1, s2, t2, l2;
inline void Reset(int a) {
  for (int i = 0; i <= n; i++) stp[a][i] = INF;
  stp[a][a] = 0;
}
inline void BFS(int t) {
  Reset(t);
  queue<int> q;
  q.push(t);
  while (!q.empty()) {
    int as = q.front();
    q.pop();
    for (int i = 0; i < vc[as].size(); i++) {
      int ap = vc[as][i];
      if (stp[t][as] + 1 < stp[t][ap]) {
        stp[t][ap] = stp[t][as] + 1;
        q.push(ap);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    vc[a].push_back(b);
    vc[b].push_back(a);
  }
  cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
  for (int i = 1; i <= n; i++) BFS(i);
  if (stp[s1][t1] > l1 || stp[s2][t2] > l2) {
    cout << -1 << endl;
    return 0;
  }
  int mini = stp[s1][t1] + stp[s2][t2];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (stp[s1][i] + stp[i][j] + stp[j][t1] <= l1 &&
          stp[s2][i] + stp[i][j] + stp[j][t2] <= l2) {
        mini = min(mini, stp[s1][i] + stp[s2][i] + stp[i][j] + stp[j][t1] +
                             stp[j][t2]);
      }
      if (stp[s1][i] + stp[i][j] + stp[j][t1] <= l1 &&
          stp[s2][j] + stp[j][i] + stp[i][t2] <= l2) {
        mini = min(mini, stp[s1][i] + stp[i][j] + stp[j][t1] + stp[s2][j] +
                             stp[i][t2]);
      }
    }
  }
  cout << m - mini << endl;
  return 0;
}

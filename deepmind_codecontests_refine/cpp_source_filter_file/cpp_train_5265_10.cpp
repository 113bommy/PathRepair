#include <bits/stdc++.h>
using namespace std;
int c[2000], ans[2000];
vector<int> b[2000][2000];
vector<int> C[2000];
vector<int> r[200];
int qq;
void solve(int x, int t) {
  for (int j = 0; j < c[t - 1]; j++) {
    for (int i = 0; i < x / 2; i++) {
      b[t][c[t]].push_back(b[t - 1][j][i]);
      r[qq].push_back(b[t - 1][j][i]);
    }
    c[t]++;
  }
  qq++;
  for (int j = 0; j < c[t - 1]; j++) {
    for (int i = x / 2; i < x; i++) {
      b[t][c[t]].push_back(b[t - 1][j][i]);
      r[qq].push_back(b[t - 1][j][i]);
    }
    c[t]++;
  }
  qq++;
  if (x > 1) solve(x / 2, t + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 1; i <= 1100; i++) ans[i] = 2e9;
  for (int i = 1; i <= 4; i++) b[0][0].push_back(i);
  for (int i = 5; i <= 1024; i++) b[0][1].push_back(i);
  for (int i = 1; i <= 512; i++) r[0].push_back(i);
  for (int i = 513; i <= 1024; i++) r[1].push_back(i);
  qq = 2;
  c[0] = 2;
  solve(1024, 1);
  int m;
  cin >> m;
  for (int i = 0; i < 20; i++) {
    for (auto j : r[i])
      if (j <= m) {
        C[i].push_back(j);
        if (C[i].size() >= m) break;
      }
    if (C[i].size() != 0) {
      cout << C[i].size() << endl;
      fflush(stdout);
      for (auto j : C[i]) {
        cout << j << endl;
        fflush(stdout);
      }
      for (int l = 1; l <= m; l++) {
        int x;
        cin >> x;
        int t = 1;
        for (int i1 = 0; i1 <= C[i].size(); i1++)
          if (C[i][i1] == l) t = 0;
        if (t == 1) ans[l] = min(ans[l], x);
      }
    }
  }
  cout << -1 << endl;
  fflush(stdout);
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << " ";
    fflush(stdout);
  }
}

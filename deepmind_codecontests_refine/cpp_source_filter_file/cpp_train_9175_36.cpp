#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, stateCnt;
vector<vector<int> > g;
vector<double> stayP;
double prob[300][300], buf[300][300];
int state[30][30];
int getState(int a, int b) {
  if (a > b) swap(a, b);
  return state[a][b];
}
void mult() {
  memset(buf, 0, sizeof(buf));
  for (int i = 0; i < stateCnt; i++)
    for (int j = 0; j < stateCnt; j++)
      for (int k = 0; k < stateCnt; k++) buf[i][j] += prob[i][k] * prob[k][j];
  memcpy(prob, buf, sizeof(buf));
}
void clean() {
  for (int i = 0; i < stateCnt; i++)
    for (int j = 0; j < stateCnt; j++)
      if (prob[i][j] < 1e-8) prob[i][j] = 0;
}
int main() {
  cin >> n >> m >> a >> b;
  stateCnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
      state[i][j] = stateCnt;
      stateCnt++;
    }
  a--, b--;
  g.resize(n);
  stayP.resize(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < n; i++) cin >> stayP[i];
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
      if (i == j)
        prob[getState(i, j)][getState(i, j)] = 1;
      else {
        prob[getState(i, j)][getState(i, j)] = stayP[i] * stayP[j];
        double ta = (1 - stayP[i]) / (int)((g[i]).size());
        double tb = (1 - stayP[j]) / (int)((g[j]).size());
        for (int b = 0; b < (int)((g[j]).size()); b++) {
          int tob = g[j][b];
          prob[getState(i, j)][getState(i, tob)] += stayP[i] * tb;
        }
        for (int a = 0; a < (int)((g[i]).size()); a++) {
          int toa = g[i][a];
          prob[getState(i, j)][getState(toa, j)] += ta * stayP[j];
        }
        for (int a = 0; a < (int)((g[i]).size()); a++)
          for (int b = 0; b < (int)((g[j]).size()); b++) {
            int toa = g[i][a];
            int tob = g[j][b];
            prob[getState(i, j)][getState(toa, tob)] += ta * tb;
          }
      }
    }
  for (int i = 0; i < 50; i++) {
    mult();
    clean();
  }
  int t = getState(a, b);
  cout.precision(9);
  for (int i = 0; i < n; i++) cout << prob[t][getState(i, i)] << ' ';
}

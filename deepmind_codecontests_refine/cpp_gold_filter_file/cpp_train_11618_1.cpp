#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int l[25000], r[25000], u[25000], was[25000], S;
vector<int> matom[15][15];
vector<int> matrec[15][15];
int x, y;
int k = 1;
int L, K, R;
vector<int> g[101010];
vector<pair<int, int> > om;
vector<pair<int, int> > rec;
queue<pair<int, int> > q;
int N;
int ot[15][15];
char m1[15][15];
char m2[15][15];
char z1[15][15];
int M;
int T;
int cupj(int q) {
  if (was[q]) return 0;
  was[q] = 1;
  for (int i = 0; i < g[q].size(); ++i) {
    if (!r[g[q][i]]) {
      l[q] = g[q][i];
      r[g[q][i]] = q;
      return 1;
    }
  }
  for (int i = 0; i < g[q].size(); ++i) {
    if (cupj(r[g[q][i]])) {
      l[q] = g[q][i];
      r[g[q][i]] = q;
      return 1;
    }
  }
  return 0;
}
void lee1() {
  pair<int, int> act;
  ot[x][y] = 1;
  while (!q.empty()) {
    act = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      if (ot[act.first + dx[i]][act.second + dy[i]] == 101010) {
        q.push(make_pair(act.first + dx[i], act.second + dy[i]));
        ot[act.first + dx[i]][act.second + dy[i]] =
            ot[act.first][act.second] + 1;
      }
    }
  }
}
int calc[15][15];
void init() {
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j) {
      calc[i][j] = 0;
    }
}
void lee2() {
  pair<int, int> act;
  act = q.front();
  calc[act.first][act.second] = 1;
  while (!q.empty()) {
    act = q.front();
    q.pop();
    if (calc[act.first][act.second] < T + 1)
      for (int i = 0; i < 4; ++i) {
        if (calc[act.first + dx[i]][act.second + dy[i]] == 0 &&
            ot[act.first + dx[i]][act.second + dy[i]] >
                calc[act.first][act.second] + 1) {
          q.push(make_pair(act.first + dx[i], act.second + dy[i]));
          calc[act.first + dx[i]][act.second + dy[i]] =
              calc[act.first][act.second] + 1;
        } else if ((!(z1[act.first][act.second] >= '1' &&
                      z1[act.first][act.second] <= '9') ||
                    ot[act.first][act.second] > calc[act.first][act.second]) &&
                   calc[act.first + dx[i]][act.second + dy[i]] == 0 &&
                   ot[act.first + dx[i]][act.second + dy[i]] >=
                       calc[act.first][act.second] + 1 &&
                   z1[act.first + dx[i]][act.second + dy[i]] > '0' &&
                   z1[act.first + dx[i]][act.second + dy[i]] <= '9') {
          q.push(make_pair(act.first + dx[i], act.second + dy[i]));
          calc[act.first + dx[i]][act.second + dy[i]] =
              calc[act.first][act.second] + 1;
        }
      }
  }
}
int main() {
  scanf("%d%d\n", &N, &T);
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      scanf("%c", &m1[i][j]);
      z1[i][j] = m1[i][j];
      if (m1[i][j] > '0' && m1[i][j] <= '9') {
        om.push_back(make_pair(i, j));
        while (m1[i][j] > '0' && m1[i][j] <= '9') {
          --m1[i][j];
          matom[i][j].push_back(k);
          ++k;
        }
      }
    }
    scanf("\n");
  }
  scanf("\n");
  L = k - 1;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      scanf("%c", &m2[i][j]);
      z1[i][j] = m2[i][j];
      if (m2[i][j] == 'Z') {
        x = i;
        y = j;
      }
      if (m2[i][j] > '0' && m2[i][j] <= '9') {
        rec.push_back(make_pair(i, j));
        while (m2[i][j] > '0') {
          --m2[i][j];
          matrec[i][j].push_back(k);
          ++k;
        }
      }
    }
    scanf("\n");
  }
  R = k - L - 1;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j) ot[i][j] = 101010;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j)
      if (m1[i][j] == 'Y') ot[i][j] = 0;
  }
  q.push(make_pair(x, y));
  lee1();
  for (int i = 0; i < om.size(); ++i) {
    init();
    q.push(om[i]);
    lee2();
    for (int j = 0; j < rec.size(); ++j) {
      int a = rec[j].first;
      int b = rec[j].second;
      if (calc[a][b] && calc[a][b]) {
        for (int i1 = 0; i1 < matom[om[i].first][om[i].second].size(); ++i1) {
          for (int j1 = 0; j1 < matrec[a][b].size(); ++j1) {
            g[matom[om[i].first][om[i].second][i1]].push_back(matrec[a][b][j1]);
          }
        }
      }
    }
  }
  int ok = 1;
  while (ok) {
    ok = 0;
    for (int i = 0; i <= L; ++i) was[i] = 0;
    for (int i = 1; i <= L; ++i)
      if (!l[i]) {
        ok |= cupj(i);
      }
  }
  for (int i = 1; i <= L; ++i)
    if (l[i] > 0) ++S;
  printf("%d\n", S);
  return 0;
}

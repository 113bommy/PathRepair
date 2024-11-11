#include <bits/stdc++.h>
using namespace std;
int n;
int m;
vector<int> v[3002];
int dist[3002][3002];
int LIS[3002][4];
int LISS[3002][4];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    q;
void dik(int b) {
  q.push(make_pair(0, b));
  while (!q.empty()) {
    if (dist[b][q.top().second] != q.top().first) {
      q.pop();
      continue;
    }
    int cur = q.top().second;
    q.pop();
    int siz = v[cur].size();
    for (int i = 0; i < siz; i++) {
      if (dist[b][v[cur][i]] > dist[b][cur] + 1) {
        dist[b][v[cur][i]] = dist[b][cur] + 1;
        q.push(make_pair(dist[b][v[cur][i]], v[cur][i]));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (dist[b][i] == INT_MAX) continue;
    if (b == i) continue;
    q.push(make_pair(dist[b][i], i));
    if (q.size() > 4) {
      q.pop();
    }
  }
  for (int i = 0; i < 4; i++) {
    if (q.size()) {
      LIS[b][i] = q.top().second;
      q.pop();
    } else {
      LIS[b][i] = -1;
    }
  }
}
pair<int, int> diameter() {
  int maxt = -1;
  int X = 0;
  for (int i = 0; i < n; i++) {
    if (maxt < dist[0][i]) {
      maxt = dist[0][i];
      X = i;
    }
  }
  maxt = -1;
  int XX = 0;
  for (int i = 0; i < n; i++) {
    if (maxt < dist[X][i]) {
      maxt = dist[X][i];
      XX = i;
    }
  }
  return make_pair(X, XX);
}
int ar[4];
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    v[a].push_back(b);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = INT_MAX;
    }
    dist[i][i] = 0;
  }
  for (int i = 0; i < n; i++) {
    dik(i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dist[j][i] != INT_MAX) {
        if (j != i) {
          q.push(make_pair(dist[j][i], j));
          if (q.size() > 4) {
            q.pop();
          }
        }
      }
    }
    for (int j = 0; j < 4; j++) {
      if (q.empty()) {
        LISS[i][j] = -1;
      } else {
        LISS[i][j] = q.top().second;
        q.pop();
      }
    }
  }
  int a1, a2, a3, a4;
  int ans = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (dist[i][j] == INT_MAX) {
        continue;
      }
      for (int k = 0; k < 4; k++) {
        if (LISS[i][k] == -1) continue;
        if (LISS[i][k] == j) continue;
        for (int kk = 0; kk < 4; kk++) {
          if (LIS[j][kk] == -1) continue;
          if (LIS[j][kk] == i) continue;
          if (LIS[j][kk] == LISS[i][k]) continue;
          int t1 = LISS[i][k];
          int t2 = LIS[j][kk];
          if (ans < dist[t1][i] + dist[i][j] + dist[j][t2]) {
            ans = dist[t1][i] + dist[i][j] + dist[j][t2];
            a1 = t1;
            a2 = i;
            a3 = j;
            a4 = t2;
          }
        }
      }
    }
  }
  a1++;
  a2++;
  a3++;
  a4++;
  printf("%d %d %d %d\n", a1, a2, a3, a4);
  return 0;
}

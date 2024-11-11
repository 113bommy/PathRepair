#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
vector<long long> edges[3050];
long long dist[3050][3050];
long long now[3050], noww[3050];
long long countt, counttt;
long long n, m;
void bfs(long long a) {
  countt = 1;
  now[1] = a;
  dist[a][a] = 0;
  long long i = 0;
  while (countt > 0) {
    i++;
    counttt = 0;
    for (long long j = 1; j <= (int)countt; j++) {
      for (long long k = 0; k < (int)edges[now[j]].size(); k++) {
        long long point = edges[now[j]][k];
        if (dist[a][point] == -1) {
          counttt++;
          noww[counttt] = point;
          dist[a][point] = i;
        }
      }
    }
    countt = counttt;
    for (long long j = 1; j <= (int)countt; j++) now[j] = noww[j];
  }
}
int main() {
  cin >> n >> m;
  for (long long i = 1; i <= (int)n; i++)
    for (long long j = 1; j <= (int)n; j++) dist[i][j] = -1;
  for (long long i = 1; i <= (int)m; i++) {
    long long a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  long long a1, a2, b1, b2, t1, t2;
  cin >> a1 >> b1 >> t1 >> a2 >> b2 >> t2;
  for (long long i = 1; i <= (int)n; i++) bfs(i);
  long long min = -1;
  if (dist[a1][b1] <= t1 && dist[a2][b2] <= t2)
    min = dist[a1][b1] + dist[a2][b2];
  else {
    cout << "-1";
    return 0;
  }
  for (long long i = 1; i <= (int)n; i++)
    for (long long j = 1; j <= (int)n; j++) {
      if (dist[a1][i] + dist[i][j] + dist[j][b1] <= t1 &&
          dist[a2][i] + dist[i][j] + dist[j][b2] <= t2 &&
          dist[a1][i] + dist[i][j] + dist[j][b1] + dist[a2][i] + dist[j][b2] <
              min)
        min =
            dist[a1][i] + dist[i][j] + dist[j][b1] + dist[a2][i] + dist[j][b2];
      if (dist[a1][i] + dist[i][j] + dist[j][b1] <= t1 &&
          dist[a2][j] + dist[i][j] + dist[i][b2] <= t2 &&
          dist[a1][i] + dist[i][j] + dist[j][b1] + dist[a2][j] + dist[i][b2] <
              min)
        min =
            dist[a1][i] + dist[i][j] + dist[j][b1] + dist[a2][j] + dist[i][b2];
    }
  cout << m - min;
  return 0;
}

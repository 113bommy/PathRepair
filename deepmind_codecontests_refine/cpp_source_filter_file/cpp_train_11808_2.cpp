#include <bits/stdc++.h>
using namespace std;
int P[3001], PA[3001];
int dist[3001][3001];
int n, k;
int bfs() {
  int ans = 0;
  queue<int> Q;
  Q.push(0);
  Q.push(1);
  memset(dist, -1, sizeof dist);
  dist[0][1] = 0;
  while (not Q.empty()) {
    int first = Q.front();
    Q.pop();
    int second = Q.front();
    Q.pop();
    if (dist[first][second] > k or first > n) continue;
    ans++;
    if (second >= n) continue;
    int pf = PA[second];
    if (pf == 0) {
      if (P[first] > 0 and dist[first][second + 1] == -1) {
        Q.push(first);
        Q.push(second + 1);
        dist[first][second + 1] = dist[first][second] + 1;
      }
    } else {
      if (P[first] > 0 and dist[second + 1][second + 2] == -1) {
        Q.push(second + 1);
        Q.push(second + 2);
        dist[second + 1][second + 2] = dist[first][second] + 1;
      }
      if (P[first] < 100 and dist[second][second + 1] == -1) {
        Q.push(second);
        Q.push(second + 1);
        dist[second][second + 1] = dist[first][second] + 1;
      }
      if (pf < 100 and P[first] > 0 and dist[first][second + 1] == -1) {
        Q.push(first);
        Q.push(second + 1);
        dist[first][second + 1] = dist[first][second] + 1;
      }
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> P[i];
  PA[n - 1] = P[n - 1];
  for (int i = n - 2; i >= 0; --i) PA[i] = max(P[i], PA[i + 1]);
  int ans;
  if (n == 1)
    ans = 1;
  else
    ans = bfs();
  cout << ans << endl;
}

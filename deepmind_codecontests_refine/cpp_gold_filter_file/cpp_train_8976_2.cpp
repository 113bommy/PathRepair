#include <bits/stdc++.h>
using namespace std;
int dist[10000][1001];
bool seen[10000][1001];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int d[10000];
  for (int i = 0; i < m; i++) scanf("%d", &d[i]);
  sort(d, d + m);
  int g, r;
  scanf("%d %d", &g, &r);
  memset(dist, 0x3f, sizeof dist);
  dist[0][0] = 0;
  deque<pair<int, int> > q;
  q.emplace_back(0, 0);
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop_front();
    int i = p.first, rem = p.second;
    if (seen[i][rem]) continue;
    seen[i][rem] = true;
    if (i > 0) {
      int nrem = rem + d[i] - d[i - 1];
      if (nrem <= g && dist[i - 1][nrem] > dist[i][rem]) {
        dist[i - 1][nrem] = dist[i][rem];
        q.emplace_front(i - 1, nrem);
      }
    }
    if (i + 1 < m) {
      int nrem = rem + d[i + 1] - d[i];
      if (nrem <= g && dist[i + 1][nrem] > dist[i][rem]) {
        dist[i + 1][nrem] = dist[i][rem];
        q.emplace_front(i + 1, nrem);
      }
    }
    if (rem == g && dist[i][0] > dist[i][rem] + 1) {
      dist[i][0] = dist[i][rem] + 1;
      q.emplace_back(i, 0);
    }
  }
  long long ans = 0x3f3f3f3f3f3f3f3fLL;
  for (int i = 0; i <= g; i++)
    if (dist[m - 1][i] != 0x3f3f3f3f)
      ans = min(ans, (long long)(g + r) * dist[m - 1][i] + i);
  if (ans >= 0x3f3f3f3f3f3f3f3fLL)
    printf("-1\n");
  else
    cout << ans << endl;
}

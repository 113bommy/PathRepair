#include <bits/stdc++.h>
using namespace std;
int N, M, C, mice[100010], cheese[100010];
pair<int, int> p[200010];
int dist[200010];
bool edge[200010];
int func(void) {
  int i, j, k, tmp;
  tmp = -(1 << 29);
  for ((i) = 0; (i) < (int)(N); (i)++)
    if (p[i].second == 1)
      tmp = p[i].first;
    else
      dist[i] = p[i].first - tmp;
  tmp = (1 << 29);
  for (i = N - 1; i >= 0; i--)
    if (p[i].second == 1)
      tmp = p[i].first;
    else
      dist[i] = min(dist[i], tmp - p[i].first);
  for ((i) = 0; (i) < (int)(N - 1); (i)++) {
    int t1 = p[i].second, t2 = p[i + 1].second, d = p[i + 1].first - p[i].first;
    if (t1 == 0 && t2 == 1 && dist[i] == d) edge[i] = true;
    if (t1 == 1 && t2 == 0 && dist[i + 1] == d) edge[i] = true;
  }
  int ans = 0;
  i = 0;
  while (i < N) {
    for (j = i; j < N; j++)
      if (!edge[j]) break;
    ans += (j - i + 1) / 2;
    bool found = false;
    if (p[i].second == 0 && p[j].second == 0)
      for (k = i; k < j; k += 2)
        if (dist[k] == dist[k + 2]) found = true;
    if (found) ans++;
    i = j + 1;
  }
  return ans;
}
int main(void) {
  int Y1, Y2, i;
  scanf("%d%d%d%d", &M, &C, &Y1, &Y2);
  for ((i) = 0; (i) < (int)(M); (i)++) scanf("%d", &mice[i]);
  for ((i) = 0; (i) < (int)(C); (i)++) scanf("%d", &cheese[i]);
  N = M + C;
  for ((i) = 0; (i) < (int)(M); (i)++) p[i] = make_pair(mice[i], 0);
  for ((i) = 0; (i) < (int)(C); (i)++) p[M + i] = make_pair(cheese[i], 1);
  sort(p, p + N);
  int ans = func();
  cout << M - ans << endl;
  return 0;
}

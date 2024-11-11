#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200257;
int N, K;
int a[MAXN], b[MAXN];
pair<int, int> dist[MAXN];
void init() {
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) scanf("%d", &a[i]);
  for (int i = 0; i < N; i++) scanf("%d", &b[i]);
  for (int i = 0; i < N; i++) {
    dist[i].first = b[i] - a[i];
    dist[i].second = i;
  }
  sort(dist, dist + N);
}
int main() {
  init();
  int Ans = 0;
  int i = N - 1;
  for (; i >= 0; i--) {
    if (i <= N - K - 1 && dist[i].first < 0) break;
    Ans += a[dist[i].second];
  }
  for (; i >= 0; i--) Ans += b[dist[i].second];
  printf("%d\n", Ans);
  return 0;
}

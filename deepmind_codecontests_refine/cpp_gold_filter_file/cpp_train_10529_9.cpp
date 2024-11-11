#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
static int N, Q, M, sum, vis[MAXN], pre[MAXN];
static pair<int, int> seg[MAXN];
inline bool cmp(const pair<int, int> a, const pair<int, int> b) {
  return a.first == b.first ? a.second > b.second : a.first < b.first;
}
inline int get_segment(int i, int j) {
  int first = i == 0 ? seg[i].first : max(seg[i].first, seg[i - 1].second + 1);
  int second =
      j == M - 1 ? seg[j].second : min(seg[j].second, seg[j + 1].first - 1);
  return max(0, second - first + 1);
}
int main() {
  scanf("%d%d", &N, &Q);
  for (int i = 0; i < Q; i++) {
    scanf("%d%d", &seg[i].first, &seg[i].second);
    for (int j = seg[i].first; j <= seg[i].second; j++) vis[j] = 1;
  }
  for (int i = 1; i <= N; i++) sum += vis[i];
  sort(seg, seg + Q, cmp);
  for (int i = 0; i < Q; i++)
    if (!i || seg[i].second > seg[M - 1].second) seg[M++] = seg[i];
  if (M <= Q - 2) return printf("%d\n", sum), 0;
  if (M == Q - 1) {
    int ans = 0;
    for (int i = 0; i < M; i++) ans = max(ans, sum - get_segment(i, i));
    printf("%d\n", ans);
  } else {
    int ans = 0;
    for (int i = 0; i < M; i++)
      for (int j = i + 1; j < M; j++) {
        if (j == i + 1)
          ans = max(ans, sum - get_segment(i, j));
        else
          ans = max(ans, sum - get_segment(i, i) - get_segment(j, j));
      }
    printf("%d\n", ans);
  }
  return 0;
}

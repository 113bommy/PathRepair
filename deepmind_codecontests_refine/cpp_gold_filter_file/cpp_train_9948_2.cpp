#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
pair<int, int> ed[MAXN];
bool u[MAXN];
int col[MAXN];
int tp[1000005];
int gr[1000005];
int main() {
  srand(time(0));
  int n, e;
  cin >> n >> e;
  for (int i = 0; i < e; i++) scanf("%d%d", &ed[i].first, &ed[i].second);
  int T = 0;
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    int mi = -1;
    for (int j = 0; j < t; j++) {
      int x;
      scanf("%d", &x);
      T = max(T, x);
      if (mi < 0 || gr[mi] > gr[x]) mi = x;
    }
    gr[mi]++;
    col[i] = mi;
  }
  for (int i = 0; i < 1000; i++) {
    for (int j = 1; j <= n; j++) {
      tp[col[j]] = rand() % 2;
    }
    int cnt = 0;
    for (int j = 0; j < e; j++) {
      if (tp[col[ed[j].first]] != tp[col[ed[j].second]]) cnt++;
    }
    if (cnt >= (e + 1) / 2) {
      for (int i = 1; i <= n; i++) printf("%d ", col[i]);
      printf("\n");
      for (int i = 1; i <= T; i++) {
        printf("%d ", tp[i] + 1);
      }
      printf("\n");
      return 0;
    }
  }
  return 0;
}

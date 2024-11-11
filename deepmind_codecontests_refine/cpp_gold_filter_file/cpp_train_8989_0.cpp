#include <bits/stdc++.h>
using namespace std;
int n, m, gxx;
pair<int, int> a[411111];
int p[411111];
int Gxx[411111], bb[411111];
int degree[411111];
int h, t;
void make_ans(int x, int y, int tot) {
  int now_x = degree[x] - 1 - tot;
  int need_x = max(h - now_x, 0);
  int now_y = degree[y] - 1 - tot;
  int need_y = max(t - now_y, 0);
  for (int i = p[x]; i < p[x + 1]; i++) Gxx[a[i].second] = 1;
  for (int i = p[y]; i < p[y + 1]; i++)
    if (Gxx[a[i].second] == 1) bb[a[i].second] = 1;
  printf("YES\n");
  printf("%d %d\n", x, y);
  bool bo = false;
  for (int i = p[x]; i < p[x + 1]; i++)
    if ((bb[a[i].second] == 0 || need_x) && a[i].second != y && h) {
      h--;
      if (bb[a[i].second]) {
        bb[a[i].second] = -1;
        need_x--;
      }
      if (bo) printf(" ");
      bo = true;
      printf("%d", a[i].second);
    }
  printf("\n");
  bo = false;
  for (int i = p[y]; i < p[y + 1]; i++)
    if ((bb[a[i].second] == 0 || need_y) && a[i].second != x && t &&
        bb[a[i].second] != -1) {
      t--;
      if (bb[a[i].second]) need_y--;
      if (bo) printf(" ");
      bo = true;
      printf("%d", a[i].second);
    }
  printf("\n");
}
int find(int x, int y) {
  int ans = 0;
  for (int i = p[x]; i < p[x + 1]; i++)
    if (a[i].second != y) {
      int t =
          lower_bound(a + p[y], a + p[y + 1], make_pair(y, a[i].second)) - a;
      if (a[t].second == a[i].second) ans++;
    }
  return ans;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &h, &t);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a[i].first, &a[i].second);
    degree[a[i].first]++;
    degree[a[i].second]++;
    a[i + m].second = a[i].first;
    a[i + m].first = a[i].second;
  }
  int M = m * 2;
  sort(a + 1, a + M + 1);
  a[0].first = 0;
  a[M + 1].first = n + 1;
  int now = 0;
  for (int i = 1; i <= M + 1; i++)
    while (now != a[i].first) {
      now++;
      p[now] = i;
    }
  p[0] = 0;
  for (int i = 1; i <= M; i++)
    if (degree[a[i].first] > h && degree[a[i].second] > t) {
      int t1 = a[i].first;
      int t2 = a[i].second;
      int tot = 0;
      if (t1 < t2)
        tot = find(t1, t2);
      else
        tot = find(t2, t1);
      if (degree[t1] + degree[t2] - 2 - tot >= h + t) {
        make_ans(t1, t2, tot);
        return 0;
      }
    }
  printf("NO\n");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int u[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int a[2000][2000], b[2000][2000];
pair<int, int> queue[400000];
bool v[2000][2000];
int sqr(int x) { return x * x; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
        b[i][j] = a[i][j];
        continue;
      }
      int cnt[2] = {0, 0};
      for (int t1 = -1; t1 <= 1; t1++)
        for (int t2 = -1; t2 <= 1; t2++) cnt[a[i + t1][j + t2]]++;
      if (cnt[0] > cnt[1])
        b[i][j] = 0;
      else
        b[i][j] = 1;
    }
  int ans1 = 0, ans2 = 0;
  memset(v, false, sizeof(v));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!v[i][j] && a[i][j] == 1) {
        queue[0] = make_pair(i, j);
        v[i][j] = true;
        int head = 0, tail = 1;
        while (head < tail) {
          pair<int, int> now = queue[head++];
          for (int k = 0; k < 4; k++) {
            int t1 = now.first + u[k][0];
            int t2 = now.second + u[k][1];
            if (0 <= t1 && t1 < n && 0 <= t2 && t2 < n && a[t1][t2] == 1 &&
                !v[t1][t2]) {
              queue[tail++] = make_pair(t1, t2);
              v[t1][t2] = true;
            }
          }
        }
        if (tail < 100) continue;
        pair<int, int> minv = make_pair(0, 0);
        pair<int, int> maxv = make_pair(n, 0);
        for (int k = 0; k < tail; k++) {
          minv = min(minv, queue[k]);
          maxv = max(maxv, queue[k]);
        }
        int t = sqr(minv.first - maxv.first + 1) +
                sqr(minv.second - maxv.second + 1);
        double s1 = fabs(tail - t * pi / 4);
        double s2 = fabs(tail - t / 2.0);
        if (s1 < s2)
          ans1++;
        else
          ans2++;
      }
  printf("%d %d\n", ans1, ans2);
  return 0;
}

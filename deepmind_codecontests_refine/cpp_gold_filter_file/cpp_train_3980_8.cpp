#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v[1000055];
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};
short dis[45][1000055];
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int a[1005][1005];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      for (int k = 0; k < 4; k++) {
        int first = i + X[k], second = j + Y[k];
        if (first >= 0 && first < n && second >= 0 && second < m) {
          v[i * m + j].push_back(make_pair(first * m + second, 1));
        }
      }
      v[a[i][j] + n * m].push_back(make_pair(i * m + j, 1));
      v[i * m + j].push_back(make_pair(a[i][j] + n * m, 0));
    }
  for (int i = 1; i <= k; i++) {
    queue<int> q1, q2;
    q1.push(n * m + i);
    fill(dis[i], dis[i] + 1000055, 6000);
    dis[i][n * m + i] = 0;
    int now = 0;
    while (!q1.empty()) {
      while (!q1.empty()) {
        int first = q1.front();
        q1.pop();
        if (dis[i][first] != now) continue;
        for (pair<int, int> &p : v[first]) {
          if (p.second == 0) {
            if (dis[i][first] < dis[i][p.first]) {
              dis[i][p.first] = dis[i][first];
              q1.push(p.first);
            }
          } else {
            if (dis[i][first] + 1 < dis[i][p.first]) {
              dis[i][p.first] = dis[i][first] + 1;
              q2.push(p.first);
            }
          }
        }
      }
      while (!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
      }
      now++;
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int r1, c1, r2, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    r1--;
    c1--;
    r2--;
    c2--;
    if (a[r2][c2] == a[r1][c1]) {
      if (r1 == r2 && c1 == c2)
        printf("0\n");
      else
        printf("1\n");
    } else {
      int ans = dis[a[r2][c2]][r1 * m + c1];
      for (int i = max(r2 - 40, 0); i < min(r2 + 40, n); i++) {
        for (int j = max(c2 - 40, 0); j < min(c2 + 40, m); j++) {
          ans = min(dis[a[i][j]][r1 * m + c1] + abs(i - r2) + abs(j - c2), ans);
        }
      }
      ans = min(ans, abs(r1 - r2) + abs(c1 - c2));
      printf("%d\n", ans);
    }
  }
}

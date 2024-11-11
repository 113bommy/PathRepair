#include <bits/stdc++.h>
const int inf = 1 << 20;
using namespace std;
long long ans1 = 0, ans2 = 0;
int n, m, r;
int d[1000], g[1000], a[1000][1000], s[1000][1000];
int w[1000][1000];
pair<int, long long> ml[1000][1000], mr[1000][1000];
void update(int i, int up, int down, int now) {
  if (up == down) up--;
  if (up >= r + 1) {
    if (ml[i][up].first + now > ans1) {
      ans1 = ml[i][up].first + now;
      ans2 = ml[i][up].second;
    } else if (ml[i][up].first + now == ans1) {
      ans2 += ml[i][up].second;
    }
  }
  if (down <= m - r) {
    if (mr[i][down].first + now > ans1) {
      ans1 = mr[i][down].first + now;
      ans2 = mr[i][down].second;
    } else if (mr[i][down].first + now == ans1) {
      ans2 += mr[i][down].second;
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &r);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) s[i][j] = s[i][j - 1] + a[i][j];
  for (int i = 0; i <= n; i++) {
    d[i] = -inf;
    for (int j = 0;; j++) {
      if (i * i + j * j <= r * r)
        d[i] = j;
      else
        break;
    }
  }
  for (int i = 0; i <= n; i++) {
    int maxx = 0;
    for (int j = 0; j <= i; j++) maxx = max(maxx, d[j] + d[i - j] + 1);
    g[i] = maxx;
  }
  for (int i = r + 1; i <= n - r; i++) {
    for (int j = r + 1; j <= m - r; j++) {
      int up, down;
      up = j - d[0] - 1;
      down = j + d[0];
      w[i][j] += s[i][down] - s[i][up];
      for (int k = 1; k <= r; k++) {
        up = j - d[k] - 1;
        down = j + d[k];
        w[i][j] += s[i + k][down] - s[i + k][up];
        w[i][j] += s[i - k][down] - s[i - k][up];
      }
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (w[i][j] > ml[i][j - 1].first) {
        ml[i][j].first = w[i][j];
        ml[i][j].second = 1;
      } else if (w[i][j] == ml[i][j - 1].first) {
        ml[i][j].first = w[i][j];
        ml[i][j].second = ml[i][j - 1].second + 1;
      } else {
        ml[i][j].first = ml[i][j - 1].first;
        ml[i][j].second = ml[i][j - 1].second;
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--) {
      if (w[i][j] > mr[i][j + 1].first) {
        mr[i][j].first = w[i][j];
        mr[i][j].second = 1;
      } else if (w[i][j] == mr[i][j + 1].first) {
        mr[i][j].first = w[i][j];
        mr[i][j].second = mr[i][j + 1].second + 1;
      } else {
        mr[i][j].first = mr[i][j + 1].first;
        mr[i][j].second = mr[i][j + 1].second;
      }
    }
  for (int i = r + 1; i <= n - r; i++) {
    for (int j = r + 1; j <= m - r; j++) {
      for (int k = r + 1; k <= n - r; k++) {
        update(k, j - g[abs(k - i)], j + g[abs(k - i)], w[i][j]);
      }
    }
  }
  if (ans1 == 0)
    puts("0 0");
  else
    cout << ans1 << " " << ans2 / 2 << endl;
  return 0;
}

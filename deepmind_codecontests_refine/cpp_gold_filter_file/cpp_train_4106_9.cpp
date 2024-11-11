#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct pi {
  int r;
} pp[2][maxn];
int cmp(pi a, pi b) { return a.r < b.r; }
int cnt[2];
long long ans = 0;
void get1(int u, int n, int m) {
  if (pp[u][0].r == pp[u][cnt[u] - 1].r) {
    long long s = m;
    s = s * (m - 1);
    s = s * (m - 2);
    s /= 6;
    ans = s;
  } else {
    int x = 0;
    int y = 0;
    for (int i = 0; i < cnt[u]; i++) {
      if (pp[u][i].r == pp[u][0].r) {
        x++;
      }
      if (pp[u][i].r == pp[u][cnt[u] - 1].r) {
        y++;
      }
    }
    if (x > 1) {
      ans += ((long long)x * (x - 1) / 2) * y;
    }
    if (y > 1) {
      ans += ((long long)y * (y - 1) / 2) * x;
    }
    ans += ((long long)x * y * (m - x - y));
  }
}
void get2(int u) {
  int x = 0, y = 0;
  for (int i = 0; i < cnt[u]; i++) {
    if (pp[u][i].r == pp[u][0].r) {
      x++;
    }
  }
  for (int i = 0; i < cnt[u ^ 1]; i++) {
    if (pp[u ^ 1][i].r == pp[u ^ 1][cnt[u ^ 1] - 1].r) {
      y++;
    }
  }
  ans += ((long long)(2 * cnt[u] - 1 - x) * x / 2) * y;
  ans += ((long long)(2 * cnt[u ^ 1] - 1 - y) * y / 2) * x;
}
pair<int, int> in[maxn];
int cmp1(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
void get3(int u) {
  long long all = 0;
  int x = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < cnt[i]; j++) {
      in[++x] = make_pair(i, pp[i][j].r);
    }
  }
  sort(in + 1, in + 1 + x, cmp1);
  int pre = 0;
  for (int i = 1; i <= x; i++) {
    int p = i;
    int x1 = 0, y1 = 0;
    while (p <= x && in[p].second == in[i].second) {
      if (in[p].first == u)
        x1++;
      else
        y1++;
      p++;
    }
    ans += ((long long)x1 * (x1 - 1) / 2) * y1;
    ans += (long long)y1 * pre * x1;
    ans += all * x1;
    pre += x1;
    all += (long long)pre * y1;
    i = p - 1;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    pp[x][cnt[x]].r = y;
    cnt[x]++;
  }
  sort(pp[0], pp[0] + cnt[0], cmp);
  sort(pp[1], pp[1] + cnt[1], cmp);
  if (cnt[1] == m) {
    get1(1, n, m);
  } else if (cnt[0] == m) {
    get1(0, n, m);
  } else if (pp[0][0].r > pp[1][cnt[1] - 1].r) {
    get2(0);
  } else if (pp[1][0].r > pp[0][cnt[0] - 1].r) {
    get2(1);
  } else {
    get3(0);
    get3(1);
  }
  cout << ans << endl;
}

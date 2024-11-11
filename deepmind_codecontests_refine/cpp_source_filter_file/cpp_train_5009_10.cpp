#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const int INF = 1000000010;
struct Point {
  int x, y;
};
map<int, bool> mapp;
map<int, int> ke;
vector<int> lvl;
vector<Point> v[N];
long long dp[N][3];
int atas, kiri, kanan, bawah, n, size_lvl;
long long cost[N];
pair<Point, Point> titik[N];
long long jarak(Point A, Point B) { return abs(A.x - B.x) + abs(A.y - B.y); }
long long itung(int now, int type) {
  if (now == size_lvl) return 0ll;
  if (dp[now][type] != -1) return dp[now][type];
  Point last;
  if (now == 0) {
    last.x = 0;
    last.y = 0;
  } else if (type == 1) {
    last = titik[now - 1].first;
  } else {
    last = titik[now - 1].second;
  }
  long long d1 = jarak(last, titik[now].first);
  long long d2 = jarak(last, titik[now].second);
  long long ans = itung(now + 1, 2) + d1;
  ans = min(ans, itung(now + 1, 1) + d2);
  return dp[now][type] = ans + cost[now];
}
int main() {
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    Point T;
    scanf("%d%d", &T.x, &T.y);
    int p = max(T.x, T.y);
    if (!mapp[p]) {
      ke[p] = cnt++;
      mapp[p] = true;
      lvl.push_back(p);
    }
    v[ke[p]].push_back(T);
  }
  memset(dp, -1, sizeof(dp));
  sort(lvl.begin(), lvl.end());
  size_lvl = lvl.size();
  for (int i = 0; i < size_lvl; i++) {
    int now = lvl[i];
    now = ke[now];
    Point p1, p2;
    kiri = INF;
    kanan = -INF;
    atas = -INF;
    bawah = INF;
    int size = v[now].size();
    for (int i = 0; i < size; i++) {
      if (v[now][i].x < kiri || (v[now][i].x == kiri && v[now][i].y > p1.y)) {
        p1 = v[now][i];
      }
      if (v[now][i].y < bawah || (v[now][i].y == bawah && v[now][i].x > p2.y)) {
        p2 = v[now][i];
      }
      kiri = min(kiri, v[now][i].x);
      kanan = max(kanan, v[now][i].x);
      atas = max(atas, v[now][i].y);
      bawah = min(bawah, v[now][i].y);
    }
    cost[i] = abs(kiri - kanan) + abs(atas - bawah);
    titik[i] = make_pair(p1, p2);
  }
  printf("%lld\n", itung(0, 0));
}

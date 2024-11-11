#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int N, M, T;
int minx, maxx;
struct node {
  int ge, y, id;
  node() {}
  node(int ge, int y, int id) : ge(ge), y(y), id(id) {}
  bool operator<(const node& t) const {
    return ge < t.ge || ge == t.ge && y < t.y;
  }
} lk[maxn];
vector<pair<int, int> > Vx[maxn];
int h[maxn];
int kk(int x, int y) {
  int m = lower_bound(h, h + 1000, y - 999) - h;
  if (m % 2 == 0) return m * 1000001 + x;
  return m * 1000001 + 1000001 - x;
}
int main() {
  cin >> N;
  minx = inf;
  for (int i = 0, j = 0; i <= 1000000; i += 1000, j++) h[j] = i;
  for (int i = 1; i <= N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    lk[i] = node(kk(x, y), y, i);
  }
  sort(lk + 1, lk + N + 1);
  for (int i = 1; i <= N; i++) printf("%d ", lk[i].id);
  return 0;
}

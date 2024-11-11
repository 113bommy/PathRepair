#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void IN(T &a) {
  char ch = getchar();
  int x = 0, f = 0;
  while (ch < '0' || ch > '9') f = (ch == '-'), ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - 48;
    ch = getchar();
  }
  a = f ? (-x) : x;
}
template <typename T>
inline void chkmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <typename T>
inline void chkmax(T &a, const T &b) {
  if (a < b) a = b;
}
int dx[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int dd[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                {0, 1},   {1, -1}, {1, 0},  {1, 1}};
const long long maxn = 1e6 + 7;
struct B {
  int days, city, cost;
  B(){};
  B(int d, int c, int cost) : days(d), city(c), cost(cost){};
} come[maxn], go[maxn];
bool cmp(B a, B b) { return a.days < b.days; }
long long jury[maxn], sum[maxn];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int d, c1, c2, money;
  int come_inc = 0, go_inc = 0;
  while (m--) {
    scanf("%d%d%d%d", &d, &c1, &c2, &money);
    if (c2 == 0) {
      come[come_inc++] = B(d, c1, money);
    } else {
      go[go_inc++] = B(d, c2, money);
    }
  }
  long long num = 0, total = 0;
  sort(come, come + come_inc, cmp);
  sort(go, go + go_inc, cmp);
  memset(sum, 0x3f, sizeof(sum));
  for (int i = int(0); i < (int)come_inc; i++) {
    if (jury[come[i].city] == 0) {
      num++;
      jury[come[i].city] = come[i].cost;
      total += come[i].cost;
    } else if (jury[come[i].city] > come[i].cost) {
      total += come[i].cost - jury[come[i].city];
      jury[come[i].city] = come[i].cost;
    }
    if (num == n) chkmin(sum[come[i].days], total);
  }
  for (int i = int(1); i < (int)maxn; i++) chkmin(sum[i], sum[i - 1]);
  num = total = 0;
  memset(jury, 0, sizeof(jury));
  long long mn = 0x3f3f3f3f3f3f3f3f;
  for (int i = int(go_inc - 1); i >= (int)0; i--) {
    if (go[i].days <= k || sum[go[i].days - k - 1] == 0x3f3f3f3f3f3f3f3f) break;
    if (jury[go[i].city] == 0) {
      num++;
      jury[go[i].city] = go[i].cost;
      total += go[i].cost;
    } else if (jury[go[i].city] > go[i].cost) {
      total += go[i].cost - jury[go[i].city];
      jury[go[i].city] = go[i].cost;
    }
    if (num == n) {
      chkmin(mn, total + sum[go[i].days - k - 1]);
    }
  }
  cout << ((mn == 0x3f3f3f3f3f3f3f3f) ? -1 : mn);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100, M = 1e5 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
inline long long read() {
  char ch = getchar();
  long long f = 1, x = 0;
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct node {
  int x, y;
} nd[N];
vector<int> b;
int c[N], mxsiz;
bool vis[N];
bool cmp(node a, node b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}
void add(int x, int v) {
  for (; x <= mxsiz; x += (x & -x)) c[x] += v;
}
int qry(int x) {
  int res = 0;
  for (; x > 0; x -= (x & -x)) res += c[x];
  return res;
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) {
    nd[i].x = read(), nd[i].y = read();
    b.push_back(nd[i].x);
  }
  sort(nd + 1, nd + 1 + n, cmp);
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  mxsiz = b.size();
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int R;
    if (i == n || nd[i + 1].y != nd[i].y)
      R = mxsiz;
    else
      R = lower_bound(b.begin(), b.end(), nd[i + 1].x) - b.begin() + 1 - 1;
    int L = lower_bound(b.begin(), b.end(), nd[i].x) - b.begin() + 1;
    if (!vis[L]) {
      add(L, 1);
      vis[L] = 1;
    }
    ans += 1ll * qry(L) * (qry(R) - qry(L - 1));
  }
  printf("%lld\n", ans);
  return 0;
}

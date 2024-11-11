#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct Dish {
  int p, s;
  int pb, pb_;
} a[N];
struct Per {
  int i;
  int ip, ip_;
  int id;
} b[N];
int n, m;
int sum[2][N << 2];
pair<int, int> c[N << 2];
int cnt;
int num;
int con1[N];
int ans[N];
bool Cmp_b(Per a, Per b) { return a.i > b.i; }
bool Cmp_a1(Dish a, Dish b) { return a.p > b.p; }
bool Cmp_a2(Dish a, Dish b) { return a.s > b.s; }
void Update(int x, int fl) {
  int *A = sum[fl];
  for (; x <= num; x += x & -x) A[x]++;
}
int Query(int x, int fl) {
  int ans = 0, *A = sum[fl];
  for (; x; x -= x & -x) ans += A[x];
  return ans;
}
int tot;
void Add(int idx) {
  tot++;
  Update(a[idx].pb, 0);
  Update(a[idx].pb_, 1);
}
int Get1(int idx) {
  int cnt = (tot << 1) - (Query(b[idx].ip, 0) + Query(b[idx].ip_, 1));
  return cnt - tot;
}
int Get2(int idx) {
  int cnt = Query(b[idx].ip, 0) + Query(b[idx].ip_, 1);
  return cnt - tot + con1[idx];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].p);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].s);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    c[++cnt] = pair<int, int>(a[i].p + x, i);
    c[++cnt] = pair<int, int>(a[i].p - x, -i);
  }
  for (int i = 1; i <= m; i++) scanf("%d", &b[i].i), b[i].id = i;
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    c[++cnt] = pair<int, int>(b[i].i + x, n + i);
    c[++cnt] = pair<int, int>(b[i].i - x, -n - i);
  }
  sort(c + 1, c + cnt + 1);
  for (int i = 1; i <= cnt; i++) {
    if (i == 1 || c[i].first > c[i - 1].first) num++;
    int k = abs(c[i].second);
    if (k <= n) {
      if (c[i].second > 0)
        a[k].pb = num;
      else
        a[k].pb_ = num;
    } else {
      if (c[i].second > 0)
        b[k - n].ip = num;
      else
        b[k - n].ip_ = num;
    }
  }
  sort(b + 1, b + m + 1, Cmp_b);
  sort(a + 1, a + n + 1, Cmp_a1);
  int p = 0;
  for (int i = 1; i <= m; i++) {
    while (p < n && a[p + 1].p > b[i].i) Add(++p);
    con1[i] = Get1(i);
  }
  sort(a + 1, a + n + 1, Cmp_a2);
  memset(sum, 0, sizeof(sum));
  tot = 0;
  p = 0;
  for (int i = 1; i <= m; i++) {
    while (p < n && a[p + 1].s >= b[i].i) Add(++p);
    ans[b[i].id] = Get2(i);
  }
  for (int i = 1; i <= m; i++) printf("%d%c", ans[i], i == m ? '\n' : ' ');
  return 0;
}

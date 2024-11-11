#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 21;
int L = 1, R = 0;
long long ans[maxn], flag[maxn];
long long Ans = 0;
int n, m, k;
struct point {
  int l, r, id;
} p[maxn];
int pos[maxn];
int a[maxn];
bool cmp(point a, point b) {
  if (pos[a.l] == pos[b.l]) return a.r < b.r;
  return pos[a.l] < pos[b.l];
}
void add(int x) {
  Ans += flag[a[x] ^ k];
  flag[a[x]]++;
}
void del(int x) {
  flag[a[x]]--;
  Ans -= flag[a[x] ^ k];
}
int main(void) {
  cin >> n >> m >> k;
  int sz = sqrt(n);
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = a[i] ^ a[i - 1];
    pos[i] = i / sz;
  }
  for (int i = 1; i <= m; i++) {
    cin >> p[i].l >> p[i].r;
    p[i].id = i;
  }
  sort(p + 1, p + 1 + m, cmp);
  flag[0] = 1;
  for (int i = 1; i <= m; i++) {
    while (L < p[i].l) {
      del(L - 1);
      L++;
    }
    while (L > p[i].l) {
      L--;
      add(L - 1);
    }
    while (R < p[i].r) {
      R++;
      add(R);
    }
    while (R > p[i].r) {
      del(R);
      R--;
    }
    ans[p[i].id] = Ans;
  }
  for (int i = 1; i <= m; i++) cout << ans[i] << endl;
  return 0;
}

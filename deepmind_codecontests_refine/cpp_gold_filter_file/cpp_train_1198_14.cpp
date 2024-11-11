#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int maxn = 1 << 20;
struct node {
  int l, r, id;
} q[maxn];
int pos[maxn];
unsigned long long ans[maxn];
unsigned long long flag[maxn];
int a[maxn];
bool cmp(node a, node b) {
  if (pos[a.l] == pos[b.l]) return a.r < b.r;
  return pos[a.l] < pos[b.l];
}
int n, m, k;
int L = 1, R = 0;
unsigned long long Ans = 0;
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
  int sz;
  sz = sqrt(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = a[i] ^ a[i - 1];
    pos[i] = i / sz;
  }
  for (int i = 1; i <= m; i++) {
    cin >> q[i].l >> q[i].r;
    q[i].id = i;
  }
  sort(q + 1, q + 1 + m, cmp);
  flag[0] = 1;
  for (int i = 1; i <= m; i++) {
    while (L < q[i].l) {
      del(L - 1);
      L++;
    }
    while (L > q[i].l) {
      L--;
      add(L - 1);
    }
    while (R < q[i].r) {
      R++;
      add(R);
    }
    while (R > q[i].r) {
      del(R);
      R--;
    }
    ans[q[i].id] = Ans;
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}

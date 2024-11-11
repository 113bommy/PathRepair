#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
struct Node {
  int l, r, id;
} a[N];
long long flag[N], pre[N];
long long ans[N], Ans = 0;
int cn[N];
int n, m, k;
int L = 1, R = 0;
bool cmp(Node a, Node b) {
  if (cn[a.l] == cn[b.l]) return a.r < b.r;
  return a.l < b.l;
}
void add(int x) {
  Ans += flag[pre[x] ^ k];
  flag[pre[x]]++;
}
void del(int x) {
  Ans -= flag[pre[x] ^ k];
  if ((pre[x] ^ k) == pre[x]) Ans++;
  flag[pre[x]]--;
}
int main() {
  cin >> n >> m >> k;
  int sz = sqrt(n);
  flag[0] = 1;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    pre[i] = pre[i - 1] ^ x;
    cn[i] = i / sz + 1;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a[i].l >> a[i].r;
    a[i].id = i;
  }
  sort(a + 1, a + 1 + m, cmp);
  for (int i = 1; i <= m; i++) {
    while (L < a[i].l) {
      del(L - 1);
      L++;
    }
    while (L > a[i].l) {
      add(L - 2);
      L--;
    }
    while (R < a[i].r) {
      add(++R);
    }
    while (R > a[i].r) {
      del(R--);
    }
    ans[a[i].id] = Ans;
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}

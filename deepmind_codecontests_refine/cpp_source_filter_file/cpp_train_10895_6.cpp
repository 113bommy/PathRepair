#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long mod = 1e9 + 7;
int n, q;
int a[N];
long long two[32];
int ans[N];
struct LB {
  int p[32];
  void init() { memset(p, 0, sizeof p); }
  bool insert(int x) {
    for (int i = 21; i >= 0; i--) {
      if ((x >> i) & 1) {
        if (p[i] == 0) {
          p[i] = x;
          return true;
        }
        x ^= p[i];
      }
    }
    return false;
  }
  int check(int x) {
    int res = 0;
    for (int i = 21; i >= 0; i--) {
      if ((x >> i) & 1) {
        if (p[i] == 0)
          return -1;
        else
          x ^= p[i];
        res++;
      }
    }
    return res;
  }
} lb;
struct Query {
  int l, id, x;
} b[N];
bool cmp(Query a, Query b) { return a.l < b.l; }
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &b[i].l, &b[i].x);
    b[i].id = i;
  }
  two[0] = 1;
  for (int i = 1; i <= 20; i++) two[i] = two[i - 1] * 2 % mod;
  sort(b + 1, b + 1 + q, cmp);
  int l = 0, size = 0;
  for (int i = 1; i <= q; i++) {
    while (l < b[i].l) {
      l++;
      if (lb.insert(a[l])) size++;
    }
    int res = lb.check(b[i].x);
    if (res != -1)
      ans[b[i].id] = two[l - size];
    else
      ans[b[i].id] = 0;
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}

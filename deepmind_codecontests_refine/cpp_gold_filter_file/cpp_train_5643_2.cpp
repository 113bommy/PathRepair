#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
long long qpow(long long x, long long y, long long MOD) {
  long long a = 1;
  while (y) {
    if (y & 1) a = a * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return a;
}
struct seg {
  int l, r, id;
} a[N];
vector<int> ans;
int c[N], d[N], p[N];
bool cmp(seg A, seg B) { return A.l == B.l ? A.r < B.r : A.l < B.l; }
struct node {
  int x, id;
  bool operator<(const node& r) const { return x < r.x; }
};
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = int(1); i <= int(n); ++i) {
    scanf("%d%d", &a[i].l, &a[i].r);
    a[i].id = i;
    c[a[i].l]++, c[a[i].r + 1]--;
  }
  sort(a + 1, a + 1 + n, cmp);
  priority_queue<node> q;
  int res = 0, cur = 1;
  for (int i = int(1); i <= int(N - 1); ++i) {
    while (a[cur].l <= i && cur <= n) q.push(node{a[cur].r, a[cur].id}), cur++;
    d[i] = d[i - 1] + c[i];
    while (d[i] > k) {
      node tp = q.top();
      q.pop();
      ans.push_back(tp.id), res++;
      d[i]--;
      c[tp.x + 1]++;
    }
  }
  printf("%d\n", res);
  for (auto i : ans) printf("%d ", i);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
struct node {
  long long v;
  int id;
  node(long long v = 0, long long id = 0) : v(v), id(id) {}
  bool operator<(const node &b) const { return v < b.v; }
};
bool cmp(node a, node b) { return a.id < b.id; }
node p[200010];
int n, A, c1, c2;
long long m, sum[200010];
bool check(long long v, bool ok) {
  bool flag = 0;
  for (int i = n; i >= 0; --i) {
    int len = n - i;
    long long left = v - 1LL * len * c1, k = m - (1LL * len * A - sum[i]);
    if (left <= 0 && k >= 0) {
      flag = 1;
      if (ok) {
        for (int j = n - 1; j >= i; --j) p[j].v = A;
      }
      break;
    }
    if (k < 0) break;
    long long mn = (left + c2 - 1) / c2;
    if (mn > A) continue;
    int pos = lower_bound(p, p + n, node(mn, 0x3f3f3f3f)) - p;
    if (pos == 0) {
      flag = 1;
      if (ok) {
        for (int j = n - 1; j >= i; --j) p[j].v = A;
      }
      break;
    }
    pos--;
    if (pos >= i) pos = i - 1;
    len = pos + 1;
    long long yong = mn * len - (sum[0] - sum[pos + 1]);
    if (yong <= k) {
      if (ok) {
        for (int j = n - 1; j >= i; --j) p[j].v = A;
        for (int j = 0; j <= pos; ++j) p[j].v = mn;
      }
      flag = 1;
      break;
    }
  }
  return flag;
}
int main() {
  scanf("%d%d%d%d%I64d", &n, &A, &c1, &c2, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%I64d", &p[i].v);
    p[i].id = i;
  }
  sort(p, p + n);
  sum[n] = 0;
  for (int i = n - 1; i >= 0; --i) sum[i] += sum[i + 1] + p[i].v;
  long long L = 0, R = 1LL * n * c1 + A + 1;
  while (L < R) {
    long long mid = (L + R) / 2;
    if (!check(mid, 0))
      R = mid;
    else
      L = mid + 1;
  }
  if (!check(L, 0)) L--;
  cout << L << endl;
  check(L, 1);
  sort(p, p + n, cmp);
  for (int i = 0; i < n; ++i) printf("%I64d ", p[i].v);
  puts("");
  return 0;
}

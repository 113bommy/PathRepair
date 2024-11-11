#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2 * 1e5 + 10;
long long a[maxn], b[maxn];
struct node1 {
  long long id, t, c, tol;
} it[maxn];
struct node2 {
  int id;
  int num;
} ans[maxn];
long long n, k, m, s;
bool cmp(struct node1 a, struct node1 b) { return a.tol < b.tol; }
bool judge(int q) {
  int mind = INF;
  int did;
  int minp = INF;
  int pid;
  for (int i = 1; i <= q; i++) {
    if (mind > a[i]) {
      did = i;
      mind = a[i];
    }
  }
  for (int i = 1; i <= q; i++) {
    if (minp > b[i]) {
      pid = i;
      minp = b[i];
    }
  }
  for (int i = 1; i <= m; i++) {
    if (it[i].t == 1) {
      it[i].tol = it[i].c * mind;
    } else {
      it[i].tol = it[i].c * minp;
    }
  }
  sort(it + 1, it + m + 1, cmp);
  long long sum = 0;
  for (int i = 1; i <= k; i++) {
    sum += it[i].tol;
  }
  if (sum <= s) {
    for (int i = 1; i <= k; i++) {
      ans[i].id = it[i].id;
      if (it[i].t == 1) {
        ans[i].num = did;
      } else {
        ans[i].num = pid;
      }
    }
    return 1;
  }
  return 0;
}
int main(void) {
  scanf("%I64d%I64d%I64d%I64d", &n, &m, &k, &s);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &b[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%I64d%I64d", &it[i].t, &it[i].c);
    it[i].id = i;
  }
  int l = 1, r = n;
  int mid;
  int an = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (judge(mid)) {
      an = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  if (an) {
    printf("%I64d\n", an);
    for (int i = 1; i <= k; i++) {
      printf("%I64d %I64d\n", ans[i].id, ans[i].num);
    }
  } else {
    printf("-1\n");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int val, id;
} node;
node a[1000005];
bool cmp(node a, node b) {
  if (a.val < b.val)
    return 1;
  else if (a.val == b.val)
    return a.id < b.id;
  return 0;
}
int dp1[1000005], dp2[1000005];
int d[1000005];
int lowbit(int x) { return x & (-x); }
void update(int x, int num) {
  while (x <= 1000003) {
    d[x] += num;
    x += lowbit(x);
  }
}
int getSum(int x) {
  int s = 0;
  while (x > 0) {
    s += d[x];
    x -= lowbit(x);
  }
  return s;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].val);
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  a[0].val = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].val == a[i - 1].val)
      dp1[a[i].id] = dp1[a[i - 1].id] + 1;
    else
      dp1[a[i].id] = 1;
  }
  a[n + 1].val = 0;
  for (int i = n; i > 0; i--) {
    if (a[i].val == a[i + 1].val)
      dp2[a[i].id] = dp2[a[i + 1].id] + 1;
    else
      dp2[a[i].id] = 1;
    update(dp2[a[i].id], 1);
  }
  long long res = 0LL;
  for (int i = 1; i < n; i++) {
    update(dp2[i], -1);
    res += getSum(dp1[i] - 1);
  }
  printf("%I64d\n", res);
  return 0;
}

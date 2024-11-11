#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int a[(200000 + 10)];
long long sum[(200000 + 10)];
int tot;
struct point {
  long long a, s;
  long long get(int i) { return a * i - s; }
};
point que[(200000 + 10)];
bool judge(point i1, point i2, point i) {
  return (i.s - i2.s) * (i2.a - i1.a) >= (i2.s - i1.s) * (i.a - i2.a);
}
void insert(long long a, long long s) {
  point tmp;
  tmp.a = a, tmp.s = s;
  while (tot >= 2 && judge(que[tot - 2], que[tot - 1], tmp)) --tot;
  que[tot++] = tmp;
}
long long query(int x) {
  int l = -1, r = tot - 1;
  while (r - l > 1) {
    int mid = l + r >> 1;
    if (que[mid].get(x) <= que[mid + 1].get(x))
      l = mid;
    else
      r = mid;
  }
  return que[r].get(x);
}
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0, init = 0;
  sum[0] = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    init += (long long)a[i] * i;
    sum[i] = sum[i - 1] + a[i];
  }
  tot = 0;
  for (int i = 2; i <= n; ++i) {
    insert(i - 1, sum[i - 2]);
    ans = max(ans, query(a[i]) + sum[i - 1] - (long long)a[i] * i);
  }
  tot = 0;
  for (int i = n - 1; i >= 1; --i) {
    insert(-(i + 1), sum[i + 1]);
    ans = max(ans, query(-a[i]) - (long long)a[i] * i + sum[i]);
  }
  printf("%I64d\n", ans + init);
}

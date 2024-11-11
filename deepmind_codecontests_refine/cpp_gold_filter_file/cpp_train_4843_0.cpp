#include <bits/stdc++.h>
using namespace std;
int n;
long long cm, cf, A, m;
const int maxx = 1e5 + 7;
struct node {
  long long val;
  int id;
} a[maxx];
long long sum[maxx];
bool cmp1(node a, node b) { return a.val < b.val; }
bool cmp2(node a, node b) { return a.id < b.id; }
bool check(long long x, long long r, long long m) {
  long long l = 0, ans;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (a[mid].val <= x) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  if (x * ans - sum[ans] <= m) {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  long long tmp;
  while (~scanf("%d%I64d%I64d%I64d%I64d", &n, &A, &cf, &cm, &m)) {
    for (int i = 1; i <= n; i++) {
      scanf("%I64d", &a[i].val);
      a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + a[i].val;
    }
    a[n + 1].val = A;
    tmp = 0;
    long long ans_s = 0, cnt_h = 0, low, ans_low = a[1].val, ans_h = n;
    for (long long i = n + 1; i >= 1; i--) {
      tmp += (A - a[i].val);
      cnt_h = n + 1 - i;
      if (m - tmp < 0) break;
      long long l = a[1].val, r = A;
      long long mid;
      while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid, i - 1, m - tmp)) {
          low = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      if (cnt_h * cf + low * cm > ans_s) {
        ans_h = i;
        ans_low = low;
        ans_s = cnt_h * cf + low * cm;
      }
    }
    printf("%I64d\n", ans_s);
    int flag = 0;
    for (int i = ans_h; i <= n; i++) {
      a[i].val = A;
    }
    sort(a + 1, a + 1 + n, cmp2);
    for (int i = 1; i <= n; i++) {
      if (flag == 0) {
        flag = 1;
      } else {
        printf(" ");
      }
      if (a[i].val <= ans_low) {
        printf("%I64d", ans_low);
      } else {
        printf("%I64d", a[i].val);
      }
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct QQ {
  long long num, val;
} a[1000005];
long long pre_sum[1000005];
long long ans = 0;
long long ans_min = 0;
bool check(long long s, long long n, long long m) {
  int l = 0, r = n - 1, pos = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid].val <= s) {
      pos = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  if (pos == -1) return 1;
  return (pos + 1) * s - pre_sum[pos] <= m;
}
long long solve(long long A, long long n, long long m) {
  long long l = 0, r = A, pp = -1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid, n, m)) {
      pp = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return pp;
}
bool cmp1(QQ a, QQ b) { return a.val < b.val; }
bool cmp2(QQ a, QQ b) { return a.num < b.num; }
long long read() {
  char str[2000];
  scanf("%s", str);
  long long ret = 0;
  for (int i = 0; i < strlen(str); i++) {
    ret = ret * 10 + str[i] - '0';
  }
  return ret;
}
int main() {
  long long n = read(), A = read(), cf = read(), cm = read(), m = read();
  for (long long i = 0; i < n; i++) {
    a[i].val = read();
    a[i].num = i;
  }
  sort(a, a + n, cmp1);
  pre_sum[0] = a[0].val;
  for (int i = 1; i < n; i++) pre_sum[i] = pre_sum[i - 1] + a[i].val;
  long long sum = 0;
  long long pre = n - 1;
  long long pp = solve(A, n, m);
  if (pp * cm >= ans) {
    ans = pp * cm;
    ans_min = pp;
  }
  for (long long i = n - 1; i >= 0; i--) {
    m -= (A - a[i].val);
    if (m < 0) break;
    sum += cf;
    long long pp = solve(A, i, m);
    if (pp * cm + sum >= ans) {
      ans = pp * cm + sum;
      ans_min = pp;
      for (long long j = pre; j >= i; j--) a[j].val = A;
      pre = i;
    }
  }
  cout << ans << endl;
  sort(a, a + n, cmp2);
  for (long long i = 0; i < n; i++) {
    if (a[i].val <= ans_min)
      cout << ans_min << " ";
    else
      cout << a[i].val << " ";
  }
  cout << endl;
}

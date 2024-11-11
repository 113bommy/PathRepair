#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int prime = 999983;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-8;
const long long mod = (long long)1e9 + 7;
const unsigned long long mx = 133333331;
inline void RI(int &x) {
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0';
}
int n, x, y;
pair<long long, int> a[100010];
long long dp[100010];
long long q[400010];
void update(int x, long double y, int rt = 1, int l = 0, int r = n) {
  if (x < l || x >= r) return;
  if (x == l && r - l == 1) {
    q[rt] = dp[l] = y;
    return;
  }
  int mid = l + r >> 1, rtl = rt << 1, rtr = rtl | 1;
  if (x < mid)
    update(x, y, rtl, l, mid);
  else
    update(x, y, rtr, mid, r);
  q[rt] = max(q[rtr], q[rtl]);
}
long long query(int ql, int qr, int rt = 1, int l = 0, int r = n) {
  if (qr <= l || ql >= r) return 0;
  if (ql <= l && qr >= r) return q[rt];
  int mid = l + r >> 1, rtl = rt << 1, rtr = rtl | 1;
  return max(query(ql, qr, rtl, l, mid), query(ql, qr, rtr, mid, r));
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    a[i].first = (long long)x * x * y;
    a[i].second = -i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    long long temp = a[i].first;
    int temp1 = -a[i].second;
    dp[temp1] = query(0, temp1) + temp;
    update(temp1, dp[temp1]);
  }
  printf("%.7f\n", pi * query(0, n));
  return 0;
}

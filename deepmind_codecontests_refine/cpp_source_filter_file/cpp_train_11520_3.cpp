#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int c1[maxn], c2[maxn], a[maxn], f1[maxn], f2[maxn];
int n, m;
int lowbit(int x) { return x & (-x); }
void add1(int x, int val) {
  while (x <= m) {
    c1[x] = max(c1[x], val);
    x += lowbit(x);
  }
}
void add2(int x, int val) {
  while (x <= m) {
    c2[x] = max(c2[x], val);
    x += lowbit(x);
  }
}
int query1(int x) {
  int res = 0;
  while (x) {
    res = max(res, c1[x]);
    x -= lowbit(x);
  }
  return res;
}
int query2(int x) {
  int res = 0;
  while (x) {
    res = max(res, c2[x]);
    x -= lowbit(x);
  }
  return res;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    a[l]++;
    a[r + 1]--;
  }
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    sum += a[i];
    a[i] = sum + 1;
  }
  for (int i = 1; i <= m; i++) {
    f1[i] = query1(a[i]) + 1;
    add1(a[i], f1[i]);
  }
  for (int i = m; i >= 1; i--) {
    f2[i] = query2(a[i]) + 1;
    add2(a[i], f2[i]);
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = max(ans, f1[i] + f2[i] - 1);
  }
  cout << ans << endl;
  return 0;
}

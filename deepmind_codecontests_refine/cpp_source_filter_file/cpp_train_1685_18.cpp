#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1.5e5 + 10;
int a[MAXN], h[MAXN];
int n, m;
int lowbit(int x) { return x & (-x); }
void update(int x) {
  int lx, i;
  while (x <= n) {
    h[x] = a[x];
    lx = lowbit(x);
    for (i = 1; i < lx; i <<= 1) h[x] = max(h[x], h[x - i]);
    x += lowbit(x);
  }
}
int query(int x, int y) {
  int ans = 0x3f3f3f3f;
  while (y >= x) {
    ans = min(a[y], ans);
    y--;
    for (; y - lowbit(y) >= x; y -= lowbit(y)) ans = min(h[y], ans);
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(h, 0, sizeof(h));
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      update(i);
    }
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
      cnt += int(a[i] > query(i + 1, n));
    }
    cout << cnt << endl;
  }
  return 0;
}

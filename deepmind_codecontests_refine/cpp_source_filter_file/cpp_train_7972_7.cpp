#include <bits/stdc++.h>
using namespace std;
struct ioi {
  int x, y, p;
};
int n, len, ans[1000001];
ioi a[1000001];
bool cmp(ioi q, ioi w) { return q.x > w.x; }
void solve1() {
  ans[1] = a[1].p;
  for (int i = 2; i <= len; i++) {
    int t = (i - 1) * 2;
    if (a[t].y > a[t + 1].y)
      ans[i] = a[t].p;
    else
      ans[i] = a[t + 1].p;
  }
}
void solve2() {
  ans[1] = a[1].p;
  ans[2] = a[2].p;
  for (int i = 2; i < len; i++) {
    int t = (i - 1) * 2 + 1;
    if (a[t].y > a[t + 1].y)
      ans[i] = a[t].p;
    else
      ans[i] = a[t + 1].p;
  }
}
void solve() {
  if (n % 2)
    solve1();
  else
    solve2();
  cout << len << "\n";
  for (int i = 1; i <= len; i++) cout << ans[i] << " ";
}
int main() {
  cin >> n;
  len = n / 2 + 1;
  for (int i = 1; i <= n; i++) cin >> a[i].x;
  for (int i = 1; i <= n; i++) cin >> a[i].y, a[i].p = i;
  sort(a + 1, a + n + 1, cmp);
  solve();
}

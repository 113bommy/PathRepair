#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
int a[MAXN];
int n, m;
void input();
bool check(int);
int dis(int, int);
void solve();
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  input();
  solve();
  return 0;
}
void input() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
}
int dis(int x, int y) {
  if (y >= x) return y - x;
  return m - x + y;
}
bool check(int p) {
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (dis(a[i], x) > p)
      if (a[i] < x)
        return false;
      else
        x = a[i];
  }
  return true;
}
void solve() {
  int l = 0, r = m, mid = (r + l) / 2;
  while (r - l > 1) {
    check(mid) ? r = mid : l = mid;
    mid = (l + r) / 2;
  }
  cout << r;
}

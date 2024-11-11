#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n;
void inp() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  return;
}
bool check(int x) {
  for (int i = 1; i < 1001; i++)
    if (i * i == x) return false;
  return true;
}
void solve() {
  int ans = -int(1e7);
  for (int i = 0; i < n; i++)
    if (check(a[i])) ans = max(ans, a[i]);
  cout << ans << '\n';
  return;
}
int main() {
  clock_t beg = clock();
  {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
  };
  inp();
  solve();
  clock_t end = clock();
  fprintf(stderr, "%.3f sec\n", (double)(end - beg) / CLOCKS_PER_SEC);
  return 0;
}

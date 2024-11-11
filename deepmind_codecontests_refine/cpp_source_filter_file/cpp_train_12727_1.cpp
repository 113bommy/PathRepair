#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
pair<int, int> query(int l, int r) {
  cout << '?' << ' ' << l << ' ' << r << endl;
  int a, b;
  cin >> a >> b;
  return make_pair(a, b);
}
int n, ans[N];
void solve(int l, int r) {
  if (!ans[l]) ans[l] = query(l, l).first;
  if (!ans[r]) ans[r] = query(r, r).first;
  if (ans[l] == ans[r]) {
    for (int i = l + 1; i <= r - 1; i++) ans[i] = ans[l];
    return;
  }
  if (l + 1 != r) {
    int mid = (l + r) >> 1;
    pair<int, int> tmp = query(l, r);
    if (tmp.first == ans[l]) {
      for (int i = l + 1; i <= l + tmp.second - 1; i++) ans[i] = ans[l];
      solve(l + tmp.second, r);
    } else if (tmp.first == ans[r]) {
      for (int i = r - tmp.second + 1; i <= r - 1; i++) ans[i] = ans[r];
      solve(l, r - tmp.second);
    } else
      solve(l, mid), solve(mid + 1, r);
  }
}
int main() {
  cin >> n;
  solve(1, n);
  cout << '!';
  for (int i = 1; i <= n; i++) cout << ' ' << ans[i];
  cout << endl;
  return 0;
}

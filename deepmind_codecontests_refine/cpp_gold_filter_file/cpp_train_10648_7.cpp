#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const int N = 2e5 + 10;
int n, a[N];
int m, x, sl[N];
int ans, f[N];
vector<pair<int, int> > v;
void cal(int x, int y) {
  for (int i = 0; i <= sl[x] + sl[y]; i++) f[i] = -1;
  f[sl[x]] = 0;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == x) cnt--;
    if (a[i] == y) cnt++;
    if (f[sl[x] + cnt] != -1)
      ans = max(ans, i - f[sl[x] + cnt]);
    else
      f[sl[x] + cnt] = i;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    m = max(m, a[i]);
    if (++sl[a[i]] > sl[x]) x = a[i];
  }
  for (int i = 1; i <= m; i++)
    if (sl[i] && i != x) v.emplace_back(sl[i], i);
  if (v.empty()) return cout << 0, 0;
  sort(v.begin(), v.end(), greater<pair<int, int> >());
  for (int i = 1; i <= min(200, (int)v.size()); i++) cal(x, v[i - 1].second);
  for (int i = 1; i <= 200; i++) cal(x, v[rnd() % v.size()].second);
  cout << ans;
  return 0;
}

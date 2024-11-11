#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void chkmax(T& x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
inline void chkmin(T& x, U y) {
  if (y < x) x = y;
}
vector<pair<int, int> > V;
char s[222222];
int main() {
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  scanf("%s", s);
  int last = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (i - last - 1 >= b) V.push_back(pair<int, int>(last + 1, i - 1));
      last = i;
    }
  }
  if (n - 1 - last >= b) V.push_back(pair<int, int>(last + 1, n - 1));
  int tot = 0;
  for (int i = 0; i < V.size(); i++) tot += (V[i].second - V[i].first + 1) / b;
  int ans = tot - a + 1;
  cout << ans << endl;
  vector<int> ret;
  for (int i = 0; i < ((int)(V.size())) && ans > 0; i++) {
    for (int j = V[i].first + b - 1; ans > 0 && j <= V[i].second; j += b)
      ret.push_back(j), ans--;
  }
  assert(((int)(ret.size())) == tot - a + 1);
  for (int i = 0; i < ((int)(ret.size())); i++)
    printf("%d%c", ret[i] + 1, i < ((int)(ret.size())) - 1 ? ' ' : '\n');
  return 0;
}

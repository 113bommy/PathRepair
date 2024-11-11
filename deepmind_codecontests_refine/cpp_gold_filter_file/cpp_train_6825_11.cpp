#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, s;
  cin >> n >> s;
  int a[n], x, buff(0), cnt(1), ans(0);
  memset(a, 0, sizeof a);
  for (int i(1); i <= n; ++i) {
    cin >> x;
    if (i == s)
      if (x)
        ++ans, ++a[0];
      else
        ++a[0];
    else if (x)
      ++a[x];
    else
      ++ans, ++buff;
  }
  for (int i(1); i < n && buff; ++i)
    if (!a[i]) ++a[i], --buff;
  for (int i(1), j(n - 1); i < j; ++i) {
    if (a[i]) continue;
    while (!a[j]) --j;
    if (i >= j) break;
    ++a[i], --a[j], ++ans;
  }
  cout << ans;
}

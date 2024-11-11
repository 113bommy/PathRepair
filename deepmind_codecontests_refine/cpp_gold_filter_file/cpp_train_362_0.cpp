#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, dat;
  cin >> n >> m;
  int c[12];
  memset(c, 0, sizeof(c));
  pair<int, int> d[n];
  for (int i = 0; i < (int)n; i++) {
    cin >> dat;
    d[i].first = dat;
    d[i].second = -1;
  }
  for (int i = n - 1; i >= 0; i--) {
    d[i].second = c[d[i].first];
    c[d[i].first]++;
  }
  long long ans = 0;
  for (int i = 0; i < (int)n; i++) {
    ans += (n - (i + 1) - d[i].second);
  }
  cout << ans << '\n';
  return 0;
}

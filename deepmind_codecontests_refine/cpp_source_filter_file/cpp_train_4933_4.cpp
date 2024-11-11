#include <bits/stdc++.h>
using namespace std;
int n, s, t;
int p[200000];
int ans = 0;
int main() {
  cin >> n >> s >> t;
  for (int i = 1; i <= n; i++) cin >> p[i];
  if (s == t) {
    cout << 0;
    return 0;
  }
  int tmp = p[s];
  while (tmp != s && tmp != t) {
    ans++;
    tmp = p[tmp];
  }
  if (tmp == t)
    cout << ans;
  else
    cout << -1;
}

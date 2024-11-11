#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimization("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx2,avx,fma")
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int i, j, a, n, m, k;
  cin >> n >> m >> k;
  vector<int> p(n);
  for (i = 0; i < n; i++) cin >> p[i];
  vector<int> s(n + 1, -1);
  for (i = 0; i < n; i++) {
    cin >> a;
    if ((s[a] == -1) || (p[s[a]] < p[i])) s[a] = i;
  }
  int ans = 0;
  for (i = 0; i < k; i++) {
    cin >> a;
    bool f = 0;
    for (j = 0; j < n; j++)
      if (s[j] == a - 1) {
        f = 1;
        break;
      }
    if (!f) ans++;
  }
  cout << ans;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, t, ans, ind, res;
int main() {
  ios_base::sync_with_stdio(0);
  static const size_t npos = -1;
  cin >> n >> m;
  map<int, int> mp;
  for (i = 1; i <= m; i++) {
    t = -1;
    for (j = 1; j <= n; j++) {
      cin >> k;
      if (k > t) {
        ind = j;
        t = k;
      }
    }
    mp[ind]++;
    res = (((res) > (mp[ind])) ? (res) : (mp[ind]));
  }
  for (i = 1; i <= n; i++) {
    if (mp[i] == res) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}

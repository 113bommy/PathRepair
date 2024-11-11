#include <bits/stdc++.h>
const int inf = (int)1e18;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n, m, a, b, c;
  cin >> n >> m;
  unordered_map<int, int> mp;
  while (m--) {
    cin >> a >> b >> c;
    if (!mp[a] && !mp[b] && !mp[c]) {
      mp[a] = 1;
      mp[b] = 2;
      mp[c] = 3;
    } else if (mp[a]) {
      if (mp[a] == 1)
        mp[b] = 2, mp[c] = 3;
      else if (mp[a] == 2)
        mp[b] = 3, mp[c] = 1;
      else
        mp[b] = 1, mp[c] = 2;
    } else if (mp[b]) {
      if (mp[b] == 1)
        mp[a] = 2, mp[c] = 3;
      else if (mp[b] == 2)
        mp[a] = 3, mp[c] = 1;
      else
        mp[a] = 1, mp[c] = 2;
    } else if (mp[c]) {
      if (mp[c] == 1)
        mp[b] = 2, mp[a] = 3;
      else if (mp[c] == 2)
        mp[b] = 3, mp[a] = 1;
      else
        mp[b] = 1, mp[a] = 2;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << mp[i] << " ";
  }
  cout << '\n';
}

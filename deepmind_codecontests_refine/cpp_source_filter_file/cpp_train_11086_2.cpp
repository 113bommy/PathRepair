#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  map<int, int> mp;
  char way[200005];
  int res[200005];
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  way[0] = 'L', way[q + 1] = 'U';
  mp[0] = 0;
  mp[n + 1] = q + 1;
  res[0] = res[q + 1] = 0;
  for (int i = 0; i < 1; i++) {
    int x, y;
    cin >> x >> y >> way[i];
    auto it = mp.lower_bound(x);
    if (it->first == x) {
      cout << 0 << endl;
      continue;
    }
    if (way[i] == 'L') it--;
    int ans = abs(it->first - x);
    if (way[i] == way[it->second]) ans += res[it->second];
    cout << (res[i] = ans) << endl;
    mp[x] = i;
  }
  return 0;
}

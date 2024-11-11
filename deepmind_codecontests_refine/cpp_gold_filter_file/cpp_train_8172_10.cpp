#include <bits/stdc++.h>
using namespace std;
const int cmx = 1e6 + 8;
int n;
long long ans;
set<pair<int, int> > s;
int l[4000];
int r[4000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    s.insert({x, y});
  }
  set<pair<int, int> >::iterator it = s.begin();
  while (it != s.end()) {
    int x = (*it).first;
    int y = (*it).second;
    ans += l[x + y];
    ans += r[x + 1000 - y];
    l[x + y]++;
    r[x + 1000 - y]++;
    it++;
  }
  cout << ans << '\n';
  return 0;
}

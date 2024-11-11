#include <bits/stdc++.h>
using namespace std;
map<long long, int> m;
map<pair<int, int>, int> mp;
int main() {
  ios::sync_with_stdio(false);
  int n, a, b;
  cin >> n >> a >> b;
  int x, y;
  long long an = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    cin >> x >> y;
    an += 2 * (m[y - a * x] - mp[pair<int, int>(x, y)]);
    mp[pair<int, int>(x, y)]++;
    m[y - a * x]++;
  }
  cout << an;
  return 0;
}

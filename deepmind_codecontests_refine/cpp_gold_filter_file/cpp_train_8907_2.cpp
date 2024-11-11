#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
vector<int> v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b, q;
  cin >> a >> b;
  for (int i = 1; i * i <= a; i++) {
    if (a % i == 0) {
      mp[i]++;
      if ((a / i) != i) mp[a / i]++;
    }
  }
  for (int i = 1; i * i <= b; i++) {
    if (b % i == 0) {
      mp[i]++;
      if ((b / i) != i) mp[b / i]++;
    }
  }
  for (auto &i : mp) {
    if (i.second == 2) v.push_back(i.first);
  }
  cin >> q;
  int l, r, pos;
  while (q--) {
    cin >> l >> r;
    pos = (upper_bound(v.begin(), v.end(), r) - v.begin());
    if (pos == 0)
      cout << -1;
    else if (v[pos - 1] < l)
      cout << -1;
    else
      cout << v[pos - 1];
    cout << "\n";
  }
  return 0;
}

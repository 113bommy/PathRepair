#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  int(n);
  cin >> (n);
  ;
  int ns[n];
  int ans = 0;
  pair<int, int> groups;
  groups.first = 0;
  groups.second = 0;
  for (int i = 0; i < n; i++) {
    cin >> ns[i];
    if (ns[i] == 1)
      groups.first++;
    else
      groups.second++;
  }
  if (groups.first == 0)
    cout << 0;
  else if (groups.second > groups.first && groups.first > 0)
    cout << groups.first;
  else {
    ans = groups.second;
    groups.first -= groups.second;
    ans += groups.first / 3;
    cout << ans << endl;
  }
}

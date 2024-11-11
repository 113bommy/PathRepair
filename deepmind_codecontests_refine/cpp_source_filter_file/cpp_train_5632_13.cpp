#include <bits/stdc++.h>
using namespace std;
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
}
int main() {
  int n, m, a;
  cin >> n >> m;
  map<int, int> mp;
  map<int, int>::iterator it;
  for (int i = 1; i <= m; i++) {
    cin >> a;
    mp[a]++;
  }
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (it = mp.begin(); it != mp.end(); it++) {
      int x = it->second / i;
      sum = sum + x;
    }
    if (sum >= n) {
      mx = max(mx, i);
    }
  }
  cout << mx << endl;
  return 0;
}

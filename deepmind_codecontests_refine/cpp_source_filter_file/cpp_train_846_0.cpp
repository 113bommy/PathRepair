#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int val;
    cin >> val;
    mp[val]++;
  }
  for (int i = 1; i <= n; i++) {
    auto it = mp.upper_bound(n - a[i] - 1);
    if (it == mp.end()) {
      it = mp.upper_bound(0);
      a[i] = (a[i] + (it->first)) % n;
      it->second--;
      if (!it->second) mp.erase(it->first);
    } else {
      a[i] = (a[i] + (it->first)) % n;
      it->second--;
      if (it->second == 0) mp.erase(it->first);
    }
  }
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}

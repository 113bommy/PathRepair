#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
map<int, pair<int, int> > mp;
int a[maxn];
int main() {
  int T;
  cin >> T;
  int flag = 0;
  for (int k = 0; k < T; k++) {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    for (int i = 0; i < n; i++) {
      if (mp.count(sum - a[i])) {
        if (mp[sum - a[i]].first != i + 1 && !flag) {
          cout << "YES" << endl;
          cout << k + 1 << ' ' << i + 1 << endl;
          cout << mp[sum - a[i]].first << ' ' << mp[sum - a[i]].second << endl;
          flag = 1;
        }
      }
    }
    if (flag) continue;
    for (int i = 0; i < n; i++) {
      mp[sum - a[i]] = make_pair(k + 1, i + 1);
    }
  }
  if (!flag) cout << "NO" << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<long long> > mp;
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  while (cin >> n >> m) {
    long long k;
    vector<int> ve;
    mp.clear();
    for (int i = 1; i <= n; i++) {
      cin >> k;
      ve.push_back(k);
    }
    sort(ve.begin(), ve.end());
    for (int i = 0; i < n; i++) {
      k = ve[i];
      long long sum = 0;
      do {
        if (mp[k].size()) {
          mp[k].push_back(mp[k].back() + sum);
        } else {
          mp[k].push_back(0);
        }
        if (k == 0)
          break;
        else
          k /= 2;
        sum++;
      } while (k != -1);
    }
    long long ans = -1;
    for (unordered_map<int, vector<long long> >::iterator it = mp.begin();
         it != mp.end(); ++it) {
      if (it->second.size() >= m) {
        sort(it->second.begin(), it->second.end());
        if (ans == -1 || ans > it->second[m - 1]) {
          ans = it->second[m - 1];
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

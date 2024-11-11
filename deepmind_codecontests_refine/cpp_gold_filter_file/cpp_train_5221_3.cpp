#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map<long long int, vector<pair<int, int>>> m;
  map<long long int, int> last;
  long long int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum = 0;
    for (int j = i; j >= 0; j--) {
      sum += a[j];
      if (j > last[sum]) {
        last[sum] = i;
        m[sum].push_back({j, i});
      }
    }
  }
  long long int maxS = -1;
  long long int ans = -1;
  for (auto it = m.begin(); it != m.end(); it++) {
    if (it->second.size() > maxS) {
      maxS = it->second.size();
      ans = it->first;
    }
  }
  cout << maxS << endl;
  for (int i = 0; i < m[ans].size(); i++) {
    cout << m[ans][i].first << " " << m[ans][i].second << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> arr[200005];
vector<pair<int, int> > tx;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n + m; i++) {
    cin >> arr[i].first;
  }
  for (int i = 0; i < n + m; i++) {
    cin >> arr[i].second;
  }
  for (int i = 0; i < n + m; i++) {
    if (arr[i].second) tx.push_back(make_pair(arr[i].first, 0));
  }
  int ni = 0;
  for (int i = 0; i < m + n; i++) {
    if (arr[i].second) {
      ni++;
      continue;
    }
    if (ni == 0)
      tx[ni].second++;
    else if (ni == m)
      tx[ni - 1].second++;
    else if (abs(tx[ni].first - arr[i].first) >
             abs(tx[ni - 1].first - arr[i].first)) {
      tx[ni].second++;
    } else {
      tx[ni - 1].second++;
    }
  }
  for (auto &it : tx) {
    cout << it.second << " ";
  }
  return 0;
}

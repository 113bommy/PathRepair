#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long int n, i, cnt = 1, maxi = 0, maxi_ind, p, q, r;
  cin >> n;
  long long int arr[n];
  vector<pair<long long int, long long int>> v;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    if (i == 0)
      v.push_back({arr[i], 0});
    else if (v[cnt - 1].first != arr[i])
      v.push_back({arr[i], i}), cnt++;
  }
  bool flag = false;
  for (i = 1; i < v.size() - 1; i++) {
    p = v[i - 1].first, q = v[i].first, r = v[i + 1].first;
    if ((p > q && q > r) || (p < q && q < r))
      continue;
    else {
      cout << 3 << endl;
      cout << v[i - 1].second + 1 << " " << v[i].second + 1 << " "
           << v[i + 1].second + 1 << endl;
      flag = true;
      break;
    }
  }
  if (!flag) cout << 0 << endl;
}

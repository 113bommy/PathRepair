#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > V;
vector<int> ans;
int n, a[1000000];
int bs(int low, int high, int val, int i) {
  int mid, sum;
  while (low <= high) {
    mid = (low + high) / 2;
    if (V[mid].first >= val) {
      low = mid + 1;
    } else {
      high = mid - 1;
      sum = V[mid].second;
    }
  }
  return (sum - i) - 1;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  V.push_back({a[n - 1], n - 1});
  ans.push_back(-1);
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] <= V[V.size() - 1].first) {
      V.push_back({a[i], i});
      ans.push_back(-1);
    } else {
      ans.push_back(bs(0, V.size() - 1, a[i], i));
    }
  }
  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}

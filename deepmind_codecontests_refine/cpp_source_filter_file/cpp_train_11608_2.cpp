#include <bits/stdc++.h>
using namespace std;
int n, mx = INT_MIN, x, arr[1000005], mn = INT_MAX, ansf, anse;
unordered_set<int> st;
vector<int> vv;
vector<pair<int, int>> v(1000005);
int main() {
  ios::sync_with_stdio(0), ios_base::sync_with_stdio(0), cin.tie(0),
      cout.tie(0);
  ;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    vv.push_back(x);
    if (!st.count(x)) {
      st.insert(x);
      v[x].first = i;
    }
    arr[x]++;
    mx = max(mx, arr[x]);
  }
  st.clear();
  for (int i = n - 1; i >= 0; --i) {
    if (!st.count(vv[i])) {
      st.insert(vv[i]);
      v[vv[i]].second = i;
    }
  }
  for (int i = 0; i < 1000000; ++i) {
    if (arr[i] == mx) {
      if (v[i].second - v[i].first < mn) {
        mn = v[i].second - v[i].first;
        ansf = v[i].first;
        anse = v[i].second;
      }
    }
  }
  cout << (ansf + 1) << " " << (anse + 1) << "\n";
  return 0;
}

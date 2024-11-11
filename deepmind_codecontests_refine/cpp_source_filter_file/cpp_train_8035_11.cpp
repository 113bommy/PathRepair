#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
const int MAX_N = 300005;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<pair<int, int> > range(n + 1, make_pair(-1, -1));
    for (int i = 0; i < n; i++) {
      if (range[arr[i]] == make_pair(-1, -1)) range[arr[i]] = make_pair(i, i);
      range[arr[i]].second = i;
    }
    vector<int> v;
    for (int i = 0; i < n + 1; i++) {
      if (range[i] != make_pair(-1, -1)) {
        v.push_back(i);
      }
    }
    int curlast = -1;
    int cnt = 0;
    int ans = 0;
    for (int x : v) {
      if (range[x].first > curlast) {
        curlast = range[x].second;
        cnt++;
        ckmax(ans, cnt);
      } else {
        curlast = range[x].second;
        cnt = 1;
        ckmax(ans, cnt);
      }
    }
    cout << (int)v.size() - cnt << "\n";
  }
}

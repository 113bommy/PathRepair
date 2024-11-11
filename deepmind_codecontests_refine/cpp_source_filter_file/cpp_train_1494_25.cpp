#include <bits/stdc++.h>
using namespace std;
const int sz = 1e6;
int arr[sz];
map<int, vector<int> > m;
int N, M, K;
int main() {
  int tmp;
  int ans = 0;
  cin >> N >> M >> K;
  for (int i = 0, lets_stop_here = (int)N; i < lets_stop_here; i++) {
    cin >> tmp;
    m[tmp].push_back(i);
  }
  for (auto &x : m) {
    vector<int> &v = x.second;
    int cnt = 1;
    int l = 0, r = 0, n = v.size(), k = K;
    while (l + 1 < n) {
      while (r + 1 < n && v[r + 1] - v[r] - 1 <= k) {
        k -= v[r + 1] - v[r] - 1;
        cnt++;
        ans = max(ans, cnt);
        r++;
      }
      ans = max(ans, cnt);
      k += v[l + 1] - v[l] - 1;
      cnt--;
      l++;
    }
  }
  cout << ans << endl;
  return 0;
}

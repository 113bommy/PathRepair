#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  while (n--) {
    int k;
    cin >> k;
    int arr[100000];
    for (int i = 0; i < k; i++) {
      cin >> arr[i];
    }
    int s = arr[0] + 1, si = arr[0] + 1;
    for (int i = 0; i < k; i++) {
      if (arr[i] >= s) {
        si += arr[i] - s + 1;
        s = arr[i] + 1;
      }
      s += 1;
    }
    int e = si + k;
    v.push_back(make_pair(si, e));
  }
  sort(v.begin(), v.end());
  int ans = 0;
  int endf = 0;
  for (auto i : v) {
    if (endf < i.first) {
      ans += i.first - endf;
      endf = ans;
    }
    endf += i.second - i.first;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}

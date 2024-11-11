#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const long long INF = 1e18;
const int MX = 1000001;
int N, K, P;
vector<int> a[2];
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K >> P;
  for (int i = (0); i < (N); ++i) {
    int cur;
    cin >> cur;
    a[cur % 2].push_back(cur);
  }
  if ((int)a[1].size() < K - P) {
    cout << "NO";
    return 0;
  }
  vector<vector<int>> ans(K);
  for (int i = (0); i < (K - P); ++i) {
    ans[i].push_back(a[1].back());
    a[1].pop_back();
  }
  if ((int)a[1].size() % 2) {
    cout << "NO";
    return 0;
  }
  if ((int)a[0].size() + (int)a[1].size() / 2 < P) {
    cout << "NO";
    return 0;
  }
  for (int i = (K - P); i < (K); ++i) {
    if (!a[0].empty()) {
      ans[i].push_back(a[0].back());
      a[0].pop_back();
    } else {
      for (int j = (0); j < (2); ++j) {
        ans[i].push_back(a[1].back());
        a[1].pop_back();
      }
    }
  }
  for (int i = (0); i < (2); ++i) {
    for (int j = (0); j < ((int)a[i].size()); ++j) {
      ans[0].push_back(a[i][j]);
    }
  }
  cout << "YES\n";
  for (int i = (0); i < ((int)ans.size()); ++i) {
    cout << (int)ans[i].size();
    for (int j = (0); j < ((int)ans[i].size()); ++j) {
      cout << " " << ans[i][j];
    }
    cout << "\n";
  }
}

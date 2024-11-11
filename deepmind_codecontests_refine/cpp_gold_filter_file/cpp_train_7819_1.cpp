#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  int global_max = 0;
  vector<int> argmax(n);
  for (int i = 0; i < n; ++i) {
    int s;
    cin >> s;
    v[i].second = s;
    for (int j = 0; j < s; ++j) {
      int temp;
      cin >> temp;
      v[i].first = max(v[i].first, temp);
    }
  }
  sort(v.begin(), v.end());
  long long ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    ans += (v[n - 1].first - v[i].first) * 1ll * v[i].second;
  }
  cout << ans;
}

#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e5 + 5;
using ll = long long;
using db = double;
int n, a[300], b[300];
vector<pair<int, int>> ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      continue;
    }
    int pos = 0;
    for (int j = i; j < n; j++) {
      if (b[j] == a[i]) {
        pos = j;
        break;
      }
    }
    while (pos != i) {
      ans.push_back(make_pair(pos - 1, pos));
      swap(b[pos], b[pos - 1]);
      pos--;
    }
  }
  cout << ans.size() << "\n";
  for (auto x : ans) {
    cout << x.first + 1 << " " << x.second + 1 << "\n";
  }
  return 0;
}

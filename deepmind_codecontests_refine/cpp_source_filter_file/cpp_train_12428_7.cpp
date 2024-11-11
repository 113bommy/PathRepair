#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(""
            ".in",
            "r")) {
    freopen(
        ""
        ".in",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  sort(v.begin(), v.end());
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += abs(v[i] - i - 1);
  }
  cout << sum;
}

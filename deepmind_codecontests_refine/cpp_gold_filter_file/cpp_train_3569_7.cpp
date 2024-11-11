#include <bits/stdc++.h>
using namespace std;
long long a[200000];
void run_case() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    long long sum = 0;
    for (int j = i + 1; j < n - 1; j++) {
      sum += a[j];
      if (sum == (a[i] ^ a[j + 1])) {
        ans.insert({i, j + 1});
      }
      if (sum > a[i] * 2) break;
    }
    sum = 0;
    for (int j = i - 1; j > 0; j--) {
      sum += a[j];
      if (sum == (a[i] ^ a[j - 1])) {
        ans.insert({j - 1, i});
      }
      if (sum > a[i] * 2) break;
    }
  }
  cout << ans.size() << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  if (fopen("input.in", "r"))
    freopen("input.in", "r", stdin), freopen("output.out", "w", stdout);
  int t;
  t = 1;
  while (t--) {
    run_case();
  }
}

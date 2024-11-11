#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (k < n + 1 || n < 5) {
    cout << -1;
    return 0;
  }
  vector<int> ans(n);
  ans[0] = a;
  ans[n - 1] = b;
  ans[1] = c;
  ans[n - 2] = d;
  int j = 1;
  unordered_set<int> S{a, b, c, d};
  for (int i = 2; i < n - 2; ++i) {
    while (S.find(j) != S.end()) ++j;
    ans[i] = j;
    ++j;
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  cout << endl;
  swap(ans[0], ans[1]);
  swap(ans[n - 2], ans[n - 1]);
  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  cout << endl;
  return 0;
}

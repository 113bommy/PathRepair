#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int a[MAXN], b[MAXN], v[MAXN];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < (n); ++i) cin >> a[i];
  for (int i = 0; i < (n); ++i) {
    cin >> b[i];
    v[i] = i;
  }
  sort(v, v + n, [](int x, int y) { return a[x] > a[y]; });
  vector<int> ans = {v[0]};
  for (int i = 1; i < n; i += 2) {
    if (i == n - 1 || b[v[i]] > b[v[i + 1]])
      ans.push_back(v[i]);
    else
      ans.push_back(v[i + 1]);
  }
  cout << ans.size() << endl;
  for (int x : ans) cout << x + 1 << " ";
  cout << endl;
  return 0;
}

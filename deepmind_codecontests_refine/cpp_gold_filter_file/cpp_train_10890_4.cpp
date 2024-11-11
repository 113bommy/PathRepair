#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 1000 + 7;
int a[N];
int b[N];
int ans[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  vector<pair<int, int>> q1, q2;
  for (int i = 1; i <= n; i++) {
    q1.push_back({a[i], i});
    q2.push_back({b[i], i});
  }
  sort(q1.begin(), q1.end());
  sort(q2.rbegin(), q2.rend());
  for (int i = 0; i < q1.size(); i++) {
    int x = q1[i].first;
    int y = q2[i].first;
    int ii = q1[i].second;
    int j = q2[i].second;
    ans[j] = x;
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}

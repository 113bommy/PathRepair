#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> v(n);
  for (int i = 0, x; i < n; i++) {
    scanf("%d", &x);
    v[i].first = x;
    v[i].second = i;
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans += abs(v[i].second - v[i + 1].second);
  }
  cout << ans << endl;
}

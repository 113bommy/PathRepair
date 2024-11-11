#include <bits/stdc++.h>
using namespace std;
vector<int> l;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int x, y;
  long long ans = 0;
  while (m--) {
    cin >> x >> y;
    ans += min(a[x], a[y]);
  }
  cout << ans;
  return 0;
}

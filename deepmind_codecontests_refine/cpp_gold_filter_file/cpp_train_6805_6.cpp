#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int ans1 = min(n, m);
  int ans2 = n + m - ans1 - 1;
  cout << ans2 << " " << ans1 << endl;
}

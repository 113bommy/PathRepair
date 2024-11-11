#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int p;
  int q;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> p;
    cin >> q;
    if (q - p > 2) ans++;
  }
  cout << ans;
}

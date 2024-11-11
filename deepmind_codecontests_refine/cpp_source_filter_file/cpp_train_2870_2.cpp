#include <bits/stdc++.h>
using namespace std;
map<int, bool> mp;
const int N = 2e5 + 12;
vector<int> v;
int n, k;
int main() {
  cin >> n >> k;
  int ans = 1e9, l, r;
  while (k--) {
    cin >> l >> r;
    ans = min(ans, r - l + 1);
  }
  cout << ans;
  for (int i = 0; i < n; i++) cout << i % ans << ' ';
}

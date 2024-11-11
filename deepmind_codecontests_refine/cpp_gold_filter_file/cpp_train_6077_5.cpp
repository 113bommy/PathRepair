#include <bits/stdc++.h>
using namespace std;
const int M = (int)(2e6 + 239);
int a[(int)(1e5 + 7)], ans[(int)(1e5 + 7)];
void rll(int x) {
  int z = x;
  vector<int> nn;
  int sol = 0;
  for (int i = 2; i <= (int)sqrt(x); i++) {
    if (z % i == 0) {
      while (z % i == 0) {
        z /= i;
      }
      nn.push_back(i);
      ans[i]++;
      sol = max(sol, ans[i]);
    }
  }
  if (z > 1) {
    ans[z]++;
    nn.push_back(z);
    sol = max(sol, ans[z]);
  }
  for (int i = 0; i < (int)nn.size(); i++) {
    ans[nn[i]] = sol;
  }
  return;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    rll(a[i]);
  }
  int sz = 1;
  for (int i = 0; i < (int)(1e5 + 7); i++) {
    sz = max(sz, ans[i]);
  }
  cout << sz << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
  return 0;
}

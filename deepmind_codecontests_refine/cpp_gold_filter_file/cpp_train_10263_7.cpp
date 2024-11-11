#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> st(n);
  for (int i = 0; i < n; i++) cin >> st[i];
  int mn = 1000000000, mx = 0;
  for (auto s : st) {
    mn = min(mn, s);
    mx = max(mx, s);
  }
  int tot = 0;
  for (auto s : st) {
    if (s > mn && s < mx) tot++;
  }
  cout << tot;
  return 0;
}

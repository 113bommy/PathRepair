#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int even = 0, odd = 0;
  while (n--) {
    int e;
    cin >> e;
    if (e % 2)
      ++odd;
    else
      ++even;
  }
  int ans = 0;
  if (odd % 2)
    ans = odd;
  else
    ans = even;
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}

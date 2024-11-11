#include <bits/stdc++.h>
using namespace std;
int n, v;
int ans = 0;
int f = 0;
int main() {
  cin >> n >> v;
  if (v >= n)
    ans = n;
  else {
    ans = v + (2 + 2 + (n - v - 1) - 1) * (n - v - 1) / 2;
  }
  cout << ans;
  return 0;
}

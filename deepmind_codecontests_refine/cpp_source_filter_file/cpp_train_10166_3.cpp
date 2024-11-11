#include <bits/stdc++.h>
const bool DEBUG = false;
using namespace std;
const long long maxn = 3e5 + 5 + 1;
const long long INF = 4e18;
const long long M = 1e9 + 7;
const int lg = 21;
#pragma GCC Optimize("Ofast")
long long y, p;
bool ok() {
  for (int i = 2; i * i <= y && i < p; i++) {
    if (y % i == 0) {
      return true;
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> p >> y;
  while (ok() and y > p) {
    y--;
  }
  cout << (y > p ? y : -1);
  return 0;
}

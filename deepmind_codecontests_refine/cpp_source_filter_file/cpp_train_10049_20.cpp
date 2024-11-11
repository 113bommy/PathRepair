#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const long long mod = 1000000007;
const int maxn = 1e5 + 5;
const double PI = acos(-1.0);
long long n, k;
void solve() {
  long long res = 0;
  cin >> n >> k;
  n--;
  k = k * 2;
  while (n > 0) {
    res += n;
    n--;
    k--;
  }
  cout << res;
}
int main() {
  solve();
  return 0;
}

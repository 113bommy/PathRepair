#include <bits/stdc++.h>
using namespace std;
const long long INF = 9999999999999999;
const double PI = acos(-1);
int main() {
  ios::sync_with_stdio(false);
  long long n, res = 0, a;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a;
    res += a * i;
  }
  cout << res;
  return 0;
}

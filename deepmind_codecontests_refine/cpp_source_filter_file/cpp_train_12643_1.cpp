#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long x, y;
  cin >> x >> y;
  long long n;
  cin >> n;
  long long ans;
  switch (n % 6) {
    case 1:
      ans = x;
      break;
    case 2:
      ans = y;
      break;
    case 3:
      ans = y - x;
      break;
    case 4:
      ans = -x;
      break;
    case 5:
      ans = -y;
      break;
    case 0:
      ans = x - y;
      break;
  }
  cout << (ans + mod) % mod;
}

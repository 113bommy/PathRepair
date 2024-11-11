#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const double oula = 0.57721566490153286060651209;
using namespace std;
int n, a, b;
bool Check(int mid) {
  int sum = a / mid;
  sum += b / mid;
  if (sum >= n) return true;
  return false;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> a >> b;
  int L = 1, R = min(a, b), mid;
  while (L <= R) {
    mid = L + R >> 1;
    if (Check(mid)) {
      L = mid + 1;
    } else {
      R = mid - 1;
    }
  }
  cout << R << endl;
}

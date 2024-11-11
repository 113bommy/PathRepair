#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if ((n - 2) % 3 == 0) {
    cout << "1 0 " << n - 1;
    return 0;
  }
  cout << "1 1 " << n - 2;
  return 0;
}

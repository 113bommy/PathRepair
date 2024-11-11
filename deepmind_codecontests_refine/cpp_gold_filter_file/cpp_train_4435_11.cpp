#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int inf = 1e18;
const double pi = 3.1415926535897932384626;
long long int mpow(long long int a, long long int b, long long int m) {
  long long int res = 1;
  while (b) {
    if (b % 2) res = res * a % m;
    a = a * a % m;
    b /= 2;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  int n;
  double h;
  cin >> n >> h;
  for (int i = 1; i < n; i++)
    cout << setprecision(12) << h * sqrt((double)i / n) << " ";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}

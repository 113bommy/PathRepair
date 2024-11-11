#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1000000007;
const double EPS = 1e-8;
const long double EULER = 2.71828182845904523536;
const long double PI = 3.14159265358979323846;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  while (cin >> n) {
    n--;
    long long ans = 1 + (n * (n + 1) * (n + 5));
    cout << ans << endl;
  }
  return 0;
}

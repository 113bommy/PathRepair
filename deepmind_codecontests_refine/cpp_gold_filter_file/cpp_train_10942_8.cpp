#include <bits/stdc++.h>
int B = 400;
using namespace std;
const long long inf = 1e18;
int MOD = 1e9 + 7;
const int mxn = 200010;
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  while (n--) {
    long long s, a, b, c;
    cin >> s >> a >> b >> c;
    long long res = (s / c) + ((s / c) / (a)) * b;
    cout << setprecision(20) << res << endl;
  }
}

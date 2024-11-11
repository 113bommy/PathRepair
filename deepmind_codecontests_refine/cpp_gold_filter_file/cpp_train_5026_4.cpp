#include <bits/stdc++.h>
using namespace std;
const long double eps = 0.0000000001;
const int MOD = 998244353;
const int INF = 1000055555;
const long long LLINF = 1223372000000000555;
const int N = 555;
const int M = 2222;
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<bool> v(4, false);
  if (a == 0 && d == 0) {
    if (b % 2 == 1)
      v[1] = true;
    else
      v[2] = true;
  } else if ((a + b) % 2 == 1) {
    v[0] = true;
    if (b + c > 0) v[1] = true;
  } else {
    v[3] = true;
    if (b + c > 0) v[2] = true;
  }
  for (int i = 0; i < 4; i++) cout << (v[i] ? "Ya " : "Tidak ");
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

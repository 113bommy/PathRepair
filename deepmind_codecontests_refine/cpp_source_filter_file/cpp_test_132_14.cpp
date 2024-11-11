#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) { return (!y ? x : gcd(y, x % y)); }
long long lcm(long long x, long long y) { return x / gcd(x, y) * y; }
void file() {}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  file();
}
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
const long double eps = 1e-9;
const int mod = 1e9 + 7;
const int N = 3e5 + 5;
void solve() {
  vector<int> v(6);
  for (int i = 0; i < 6; i++) cin >> v[i];
  sort((v).begin(), (v).end());
  if (v[2] == v[1] + v[0]) {
    cout << v[0] << " " << v[1] << " " << v[3] << "\n";
  } else {
    cout << v[0] << " " << v[1] << " " << v[2] << "\n";
  }
}
int main() {
  fast();
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

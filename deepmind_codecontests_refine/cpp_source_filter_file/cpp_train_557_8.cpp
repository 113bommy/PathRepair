#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void c_p_c() {}
void solve() {
  long long n, k = 0;
  cin >> n;
  long long i = 0;
  char res[100000];
  while (n--) {
    long long x, y;
    cin >> x >> y;
    if (x + k <= 500) {
      k += x;
      res[i++] = 'A';
    } else {
      k -= x;
      res[i++] = 'G';
    }
  }
  cout << res << endl;
}
int32_t main() {
  c_p_c();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}

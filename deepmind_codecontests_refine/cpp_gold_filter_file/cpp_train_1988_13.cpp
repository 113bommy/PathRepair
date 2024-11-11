#include <bits/stdc++.h>
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end() {}
int n, L, R;
int ask(int id) {
  cout << "? " << id << endl;
  int res;
  cin >> res;
  return res;
}
inline void solve() {
  cin >> n;
  L = ask(1), R = ask(n / 2 + 1);
  int L1 = 2, R1 = n / 2, res = -1;
  if (L == R) return puts("! 1"), void();
  while (L1 <= R1) {
    int mid = (L1 + R1) >> 1;
    int L2 = ask(mid), R2 = ask(mid + n / 2);
    if ((L - R) * (L2 - R2) >= 0) {
      L1 = mid + 1;
      if (L2 == R2) return printf("! %d\n", mid), void();
    } else
      R1 = mid - 1;
  }
  cout << "! " << -1 << endl;
}
int main() {
  TIME__START = clock();
  int Test = 1;
  while (Test--) {
    solve();
  }
  TIME__END = clock();
  program_end();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
inline int ones(unsigned x) {
  int r = 0;
  while (x != 0) r++, x = x & (x - 1);
  return r;
}
using vi = vector<int>;
using pii = pair<int, int>;
using vii = vector<pii>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int inf = 0x3f3f3f3f;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long t, a, b, k;
  cin >> t;
  while (t--) {
    cin >> a >> b >> k;
    long x = (a - b) * (k / 2);
    if (k % 2 == 1) x += a;
    cout << x << endl;
  }
}

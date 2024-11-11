#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const long double PI = 3.14159265358979323846;
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const long long LINF = numeric_limits<long long>::max();
const long long mod = 1000 * 1000 * 1000 + 7;
void solve() {
  long long n, q;
  cin >> n >> q;
  for (int i = 0; i < q; ++i) {
    int x;
    cin >> x;
    while ((x & 1) == 0) {
      long long fr = x / 2;
      long long m = n - fr;
      x += m;
    }
    cout << (x + 1) / 2 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  solve();
  return 0;
}

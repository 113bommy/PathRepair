#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
const double PI = acos(-1.0);
const int INF = 1e9;
const int MOD = INF + 7;
const double EPS = 1e-9;
const long long BIGINF = 1e17;
mt19937 rng(time(0));
uniform_int_distribution<int> uid(0, INF / 2);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    long long n, l, r;
    cin >> n >> l >> r;
    if (l == 1 || r == 1 || n % l == 0 || n % r == 0 || n % r >= l) {
      cout << "Yes" << '\n';
      continue;
    }
    if (n / l * r >= n)
      cout << "Yes" << '\n';
    else
      cout << "No" << '\n';
  }
  return 0;
}

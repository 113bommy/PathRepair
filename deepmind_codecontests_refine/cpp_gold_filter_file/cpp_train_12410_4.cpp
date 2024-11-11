#include <bits/stdc++.h>
using namespace std;
long long n, x, k, z, m, pos, q, ans_v, y;
long long x1, p1, x2;
long long a[2000500], b[205000], c[200500], fac[55];
vector<long long> g[1005000];
long long dp[55];
vector<long long> f;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> x >> y;
    long long mx = 0, my = 0;
    for (int i = 0; i < x; i++) {
      long long z;
      cin >> z;
      mx = max(mx, z);
    }
    for (int i = 0; i < y; i++) {
      long long z;
      cin >> z;
      my = max(my, z);
    }
    if (my > mx) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}

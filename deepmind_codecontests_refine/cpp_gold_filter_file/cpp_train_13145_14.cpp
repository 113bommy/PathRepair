#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long MAXN = 2e5 + 5;
long long cost[6];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    for (int i = 0; i < 6; i++) {
      cin >> cost[i];
    }
    long long c = 1e18;
    if (n >= 0 && m >= 0) {
      if (n >= m) {
        c = min(n * cost[5] + m * cost[1],
                min(n * cost[0] + (n - m) * cost[4],
                    m * cost[0] + (n - m) * cost[5]));
      }
      if (n < m) {
        c = min(n * cost[5] + m * cost[1],
                min(n * cost[0] + (m - n) * cost[1],
                    m * cost[0] + (m - n) * cost[2]));
      }
    } else if (n <= 0 && m >= 0) {
      c = min((-1) * n * cost[2] + m * cost[1],
              min((-1) * n * cost[3] + (m - n) * cost[1],
                  m * cost[0] + cost[2] * (m - n)));
    } else if (n >= 0 && m <= 0) {
      c = min(n * cost[5] + (-1) * cost[4] * m,
              min((-1) * m * cost[3] + (n - m) * cost[5],
                  n * cost[0] + (n - m) * cost[4]));
    } else if (n <= 0 && m <= 0) {
      n = (-1) * n;
      m = (-1) * m;
      if (n >= m) {
        c = min(n * cost[2] + m * cost[4],
                min(n * cost[3] + (n - m) * cost[1],
                    m * cost[3] + (n - m) * cost[2]));
      } else {
        c = min(n * cost[2] + m * cost[4],
                min(n * cost[3] + (m - n) * cost[4],
                    m * cost[3] + (m - n) * cost[5]));
      }
    }
    cout << c << endl;
  }
}

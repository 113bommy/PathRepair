#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30);
const long long inf = (1LL << 58LL);
const long long MOD = (1e9 + 7);
const int maxn = 1e5 + 10;
;
int n;
int main() {
  ios_base::sync_with_stdio(false);
  int tt;
  cin >> tt;
  if (tt <= 50) {
    set<long long> st;
    int n = tt;
    for (long long i = 0; i <= n; i++) {
      for (long long j = 0; j <= n; j++) {
        for (long long k = 0; k <= n; k++) {
          for (long long x = 0; x <= n; x++) {
            if (i + j + k + x == n) {
              st.insert(1 * i + 5 * j + 10 * k + 50 * x);
            }
          }
        }
      }
    }
    cout << (int)st.size() << endl;
    return 0;
  }
  long long rr = 2203;
  int c = 50;
  while (c <= tt) {
    c++;
    rr += 49;
  }
  cout << rr << endl;
  return 0;
}

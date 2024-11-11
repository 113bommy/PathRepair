#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 23;
const long long MOD = 1e9 + 7;
const int N = 1e6 + 10;
bool prime[N];
void pre() {
  fill(prime, prime + N, true);
  for (int i = (2); i < (N); ++i) {
    if (!prime[i]) continue;
    for (int j = (i + i); j < (N); j += (i)) prime[j] = false;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  pre();
  int n;
  cin >> n;
  for (int _ = 0; _ < (n); ++_) {
    long long x;
    cin >> x;
    int sq = sqrt(x);
    if (sq * 1LL * sq != x || !prime[sq]) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
  return 0;
}

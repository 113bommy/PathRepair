#include <bits/stdc++.h>
using namespace std;
long long digit(long long a) {
  long long Min = 10, Max = -1;
  while (a > 0) {
    Min = min(Min, a % 10);
    Max = max(Max, a % 10);
    a /= 10;
  }
  return Min * Max;
}
void solve() {
  long long a1, K;
  cin >> a1 >> K;
  long long a = a1;
  for (long long i = 2; i <= K; i++) {
    long long d = digit(a);
    if (d == 0) {
      break;
    }
    a += d;
  }
  cout << a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

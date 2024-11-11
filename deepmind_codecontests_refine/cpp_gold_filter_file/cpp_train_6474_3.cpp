#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
long long a, b;
long long pwer(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a % M;
  if (b % 2 == 1) {
    return (pwer((a * a) % M, b / 2) % M) * (a % M);
  } else {
    return pwer((a * a) % M, b / 2) % M;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b;
  long long ans = (pwer(2, b) - 1) % M;
  ans = pwer(ans, a) % M;
  cout << ans << endl;
  return 0;
}

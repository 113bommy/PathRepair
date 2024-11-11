#include <bits/stdc++.h>
using namespace std;
long long N = 0, a = 0, b = 0, c = 0;
void solve() {
  long long ST = N;
  while (N % 4) {
    N++;
  }
  N = N - ST;
  if (N == 0)
    cout << 0;
  else if (N == 1) {
    cout << min(a, min(b + c, 3 * c));
  } else {
    if (N == 2)
      cout << min(2 * a, min(b, c * 2));
    else
      cout << min(3 * a, min(a + b, c));
  }
}
int main() {
  scanf("%lld%lld%lld%lld", &N, &a, &b, &c);
  solve();
  return 0;
}

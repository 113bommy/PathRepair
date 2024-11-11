#include <bits/stdc++.h>
using namespace std;
const int mod = int(1e9 + 7), MAXN = int(2e5 + 1);
long long n, q, x;
void solve(long long x) {
  if (x % 2 == 1)
    printf("%d\n", (x + 1) / 2);
  else {
    x += n - (x / 2);
    solve(x);
  }
}
int main() {
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    cin >> x;
    solve(x);
  }
  return 0;
}

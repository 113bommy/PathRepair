#include <bits/stdc++.h>
using namespace std;
long long solve(long long l, long long r) {
  if (l == r) return l;
  int b = log2(r);
  if (1LL << b <= l) return solve(l - (1LL << b), r - (1LL << b)) + (1LL << b);
  if (1LL << (b + 1) < r) return (1LL << (b + 1)) - 1;
  return (1LL << b) - 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    long long l, r;
    cin >> l >> r;
    cout << solve(l, r) << "\n";
  }
  return 0;
}

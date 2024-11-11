#include <bits/stdc++.h>
using namespace std;
const int B = 11;
const int N = 20;
long long memo[N][B];
int base;
long long l, r;
long long solve(int n, int odd) {
  if (odd > base) {
    return 0;
  }
  if (odd < 0) {
    return 0;
  }
  if (n == 0) {
    return odd == 0;
  }
  long long& res = memo[n][odd];
  if (res != -1) return res;
  res = odd * solve(n - 1, odd - 1);
  res += (base - odd) * solve(n - 1, odd + 1);
  return res;
}
long long solve(long long mx) {
  if (mx == 0) return 0;
  memset(memo, -1, sizeof memo);
  vector<int> digits;
  while (mx != 0) {
    digits.push_back(mx % base);
    mx /= base;
  }
  long long res = 0;
  for (int i = 1; i < digits.size(); ++i) {
    for (int d = 1; d < base; ++d) {
      res += solve(digits.size() - i - 1, 1);
    }
  }
  int odd = 0;
  bool first = true;
  while (!digits.empty()) {
    for (int i = first; i < digits.back(); ++i) {
      int tmp = odd;
      tmp ^= (1 << i);
      res += solve(digits.size() - 1, (__builtin_popcountll(tmp)));
    }
    odd ^= (1 << digits.back());
    digits.pop_back();
    first = false;
  }
  res += ((__builtin_popcountll(odd)) == 0);
  return res;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    cin >> base >> l >> r;
    cout << solve(r) - solve(l - 1) << '\n';
  }
}

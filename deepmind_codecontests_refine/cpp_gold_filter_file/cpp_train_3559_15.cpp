#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, p, ans = -1, new_n;
  cin >> n >> p;
  for (long long i = 1; i < 5000; i++) {
    long long new_n = n - p * i;
    if (new_n < 0) {
      continue;
    }
    long long cnt = __builtin_popcountll(new_n);
    if (new_n >= i && cnt <= i) {
      ans = i;
      break;
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 0; i < 1; i++) {
    solve();
    cout << '\n';
  }
  return 0;
}

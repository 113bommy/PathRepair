#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long k, pow, num;
  cin >> k;
  if (k == 1) {
    cout << "1 1" << '\n';
    return;
  }
  long long i = 1;
  for (; i * i < k; i++) {
  }
  long long totlen = (i - 1) * 2;
  long long diff = (i * i) - k;
  if (diff <= (totlen / 2)) {
    cout << i << ' ' << 1 + diff << '\n';
  } else {
    cout << i - (diff - (totlen / 2)) << ' ' << 1 + (totlen / 2) << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

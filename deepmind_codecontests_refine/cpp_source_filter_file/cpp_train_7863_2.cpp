#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long cnt = 0;
  vector<long long> b(n + 1);
  b[0] = 3;
  for (int(i) = (1); (i) <= (n); (i)++) {
    cin >> b[i];
    if (b[i] == b[i - 1] && b[i] != 3) {
      cnt++;
    } else if (b[i] == 3 && b[i - 1] != 3) {
      b[i] -= b[i - 1];
    }
    if (b[i] == 0) cnt++;
  }
  cout << cnt << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  while (T--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long x;
    cin >> x;
    long long y;
    cin >> y;
    long long diff = y - x;
    n--;
    long long mn_diff = (y - x + n - 1) / n;
    n++;
    while (diff % mn_diff != 0) {
      mn_diff++;
    }
    for (long long i = y; i > 0; i -= mn_diff) {
      if (n > 0) {
        cout << i << ' ';
        n--;
      } else {
        break;
      }
    }
    while (n--) {
      cout << y + mn_diff * (n + 1) << ' ';
    }
    cout << '\n';
  }
}
signed main(signed argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  if (argc > 1 && (string)argv[1] == "local") {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    while (cin.peek() != -1) {
      cout << '\n';
      cout << '\n';
      solve();
    }
  } else {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void read(T&... a) {
  ((cin >> a), ...);
}
template <typename... T>
void write(T&... a) {
  ((cout << a << " "), ...);
  cout << "\n";
}
void solve() {
  long long n;
  cin >> n;
  int cnt = 0;
  while (1) {
    if (n < 6) {
      if (n == 3) {
        cout << cnt + 2 << "\n";
        break;
      } else if (n == 1) {
        cout << cnt << "\n";
        break;
      } else {
        cout << -1 << "\n";
        break;
      }
    } else {
      if (n % 6 != 0)
        n *= 2;
      else
        n /= 6;
    }
    cnt++;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}

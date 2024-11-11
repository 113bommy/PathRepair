#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    long long a, b, n, S, flag = 0;
    cin >> a >> b >> n >> S;
    if (S <= (n * a + b)) {
      if (S >= (n * a)) {
        if (b >= (S - n * a)) flag = 1;
      } else {
        if (S % n <= b) flag = 1;
      }
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
}

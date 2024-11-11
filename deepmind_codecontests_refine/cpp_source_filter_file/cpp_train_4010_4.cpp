#include <bits/stdc++.h>
using namespace std;
int n, k;
int g(int n) {
  if (k % 2 == 0) {
    if (n == 1) return 1;
    if (n == 0) return 0;
    if (n == 2) return 2;
    return n % 2 == 0;
  } else {
    if (n == 1 || n == 3) return 1;
    if (n == 0 || n == 2) return 0;
    if (n == 6) return 2;
    if (n % 2 == 1) return 0;
    if (n % 2 == 0) {
      if ((n / 2) % 2 == 0) return 2;
      return 1;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0),
      cout.precision(15);
  cin >> n >> k;
  int ans = 0;
  for (int i = int(0); i < int(n); i++) {
    int r;
    cin >> r;
    if (i == 0)
      ans = g(r);
    else
      ans ^= g(r);
  }
  if (ans)
    cout << "Kevin" << endl;
  else
    cout << "Nicky" << endl;
}

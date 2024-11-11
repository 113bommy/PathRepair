#include <bits/stdc++.h>
using namespace std;
bool prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  if (n == 3) {
    cout << 1 << "\n" << 3 << "\n";
  } else if (n == 5) {
    cout << 2 << "\n" << 2 << ' ' << 3 << "\n";
  } else {
    n -= 3;
    for (int i = 2; i <= n; i++) {
      if (prime(i) && prime(n - i)) {
        cout << 3 << "\n" << 3 << ' ' << i << ' ' << n - i << "\n";
        break;
      }
    }
  }
  return 0;
}

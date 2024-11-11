#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  int n, m;
  cin >> n >> m;
  if (!isPrime(m)) {
    cout << "NO\n";
  } else {
    bool c = true;
    for (int i = n; i < m; i++) {
      if (isPrime(i)) {
        cout << "NO\n";
        c = false;
        break;
      }
    }
    if (c) cout << "YES\n";
  }
}

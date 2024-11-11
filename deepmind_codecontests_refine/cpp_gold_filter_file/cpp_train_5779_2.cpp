#include <bits/stdc++.h>
using namespace std;
using namespace std;
bool prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int n, p1, p2, p3, d;
  cin >> n;
  for (int i = n; i >= 2; i--) {
    if (i == n && prime(i)) {
      cout << 1 << '\n' << i << endl;
      exit(0);
    } else {
      if (prime(i)) {
        p1 = i;
        break;
      }
    }
  }
  d = n - p1;
  if (d == 2) {
    cout << 2 << '\n' << p1 << " " << 2 << endl;
    exit(0);
  }
  for (int i = 2; i < d; i++) {
    if (prime(i) && prime(d - i)) {
      p2 = i;
      p3 = d - i;
      break;
    }
  }
  cout << 3 << '\n' << p1 << " " << p2 << " " << p3 << endl;
  return 0;
}

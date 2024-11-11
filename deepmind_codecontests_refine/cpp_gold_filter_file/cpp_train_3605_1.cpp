#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, m1 = -1, m2 = -1, x;
  long long s = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    s += x;
  }
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x > m1) {
      m2 = m1;
      m1 = x;
    } else if (x > m2) {
      m2 = x;
    }
  }
  cout << (s <= m1 + m2 ? "YES\n" : "NO\n");
  return 0;
}

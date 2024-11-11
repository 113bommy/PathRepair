#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q, p;
  cin >> p >> q;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    if (p <= 0 || q <= 0) {
      cout << "NO";
      return 0;
    }
    if (p / q < a) {
      cout << "NO";
      return 0;
    }
    p -= a * q;
    swap(p, q);
  }
  if (q == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}

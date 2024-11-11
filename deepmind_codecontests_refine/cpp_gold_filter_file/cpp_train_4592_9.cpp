#include <bits/stdc++.h>
using namespace std;
bool isp(long long x) {
  for (long long a = 2; a * a <= x; a++) {
    if (x % a == 0) {
      return true;
    }
  }
  return false;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long a, b;
    cin >> a >> b;
    if ((a - b) > 1) {
      cout << "NO";
    } else {
      if (isp(a + b)) {
        cout << "NO";
      } else {
        cout << "YES";
      }
    }
    cout << endl;
  }
}

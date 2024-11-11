#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    long long a, b, sub;
    cin >> a >> b;
    if (b > a) {
      std::swap(a, b);
    }
    sub = a - b;
    if (sub > 1) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}

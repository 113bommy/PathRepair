#include <bits/stdc++.h>
using namespace std;
int d[1000001] = {0};
int sum[1000001] = {0};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a = -1, b = -1, c;
    for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0 && a == -1) {
        a = i;
      } else if (a != -1 && n % i == 0) {
        b = i;
        break;
      }
    }
    c = n / (a * b);
    if (c == 1 || b == -1 || c == b || c == a) a = -1;
    if (a == -1)
      cout << "NO\n";
    else
      cout << "YES"
           << "\n"
           << a << ' ' << b << ' ' << c << endl;
  }
}

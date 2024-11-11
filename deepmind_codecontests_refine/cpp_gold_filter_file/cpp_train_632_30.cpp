#include <bits/stdc++.h>
using namespace std;
void run() {
  long long n, k, q;
  cin >> n >> k >> q;
  for (int i = 0; i < q; i++) {
    long long a;
    cin >> a;
    if (k <= 1) {
      cout << (k == 0 || a != n ? "." : "X");
    } else if (n % 2) {
      cout << (a != n - 1 && (n != k && a == 1 ||
                              a % 2 == 1 && a != n && a / 2 + 1 + k <= n ||
                              a % 2 == 0 && n / 2 + a / 2 + k <= n)
                   ? "."
                   : "X");
    } else {
      cout << (a % 2 == 0 && a / 2 + k <= n / 2 ||
                       a % 2 == 1 && (a + 1) / 2 + k <= n
                   ? "."
                   : "X");
    }
  }
  cout << endl;
}
int main() {
  run();
  return 0;
}

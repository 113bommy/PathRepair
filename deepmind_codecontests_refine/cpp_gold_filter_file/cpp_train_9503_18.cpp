#include <bits/stdc++.h>
using namespace std;
const int N = 10001;
const int INF = 1e9;
int main() {
  long long n, f1 = 1, f2 = 1, f3 = 1;
  cin >> n;
  int m = n / 2;
  if (n == 2) {
    cout << 1;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    f1 *= i;
  }
  cout << (f1 * 2 / (n * n));
}

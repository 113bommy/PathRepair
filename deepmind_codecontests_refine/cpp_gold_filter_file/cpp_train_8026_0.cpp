#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long N;
  cin >> N;
  long long x = 0, y = 0;
  for (long long i = 0; i < N; i++) {
    long long a, b;
    cin >> a >> b;
    if ((a > x || b > y) && (a + b > x + y)) {
      x = a;
      y = b;
    }
  }
  cout << x + y << endl;
}

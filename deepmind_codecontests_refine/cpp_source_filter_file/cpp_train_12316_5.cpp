#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, l, m, n, d, count = 0;
  cin >> k >> l >> m >> n >> d;
  for (int i = 0; i < d; i++) {
    if (i % k == 0) {
      count++;
    } else if (i % l == 0) {
      count++;
    } else if (i % m == 0) {
      count++;
    } else if (i % n == 0) {
      count++;
    }
  }
  cout << count;
  return 0;
}

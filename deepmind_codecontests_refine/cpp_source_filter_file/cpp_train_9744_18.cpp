#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, b;
  cin >> n >> b;
  int t, a = 0;
  for (int i = 0; i < n; i++) {
    cin >> t;
    a += t;
  }
  double tmp = 0;
  for (int i = 0; i < 1000; i++) {
    tmp = a + i * b;
    tmp /= i + n;
    if (int(tmp + 0.5) == b) {
      cout << i << "\n";
      break;
    }
  }
  return 0;
}

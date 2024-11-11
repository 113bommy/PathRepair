#include <bits/stdc++.h>
using namespace std;
using namespace std;
void test_case() {
  int n;
  cin >> n;
  long long pow = 0;
  for (int i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (i & 1) {
        cout << 0 << " ";
        cout.flush();
      } else {
        cout << (1LL << (pow + j)) << " ";
        cout.flush();
      }
    }
    cout << "\n";
    cout.flush();
    pow++;
  }
  long long q, k;
  cin >> q;
  while (q--) {
    cin >> k;
    int x = 1, y = 0, p = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
      if ((k >> p) & 1) {
        if (x & 1) {
          y++;
        } else {
          x++;
        }
      } else {
        if (x & 1) {
          x++;
        } else {
          y++;
        }
      }
      p++;
      cout << x << " " << y << "\n";
      cout.flush();
    }
  }
}
int main() {
  test_case();
  return 0;
}

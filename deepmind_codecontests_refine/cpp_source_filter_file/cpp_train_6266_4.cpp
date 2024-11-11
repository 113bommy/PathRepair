#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a = 4, b = 5;
  while (a <= n) {
    if (a == n || b == n) {
      cout << 1 << endl;
      return 0;
    }
    if (a % 2 == 0) {
      a = 2 * a + 1;
      b = a + 1;
    } else {
      b = 2 * b + 1;
      a = b - 1;
    }
  }
  cout << 0 << endl;
  return 0;
}

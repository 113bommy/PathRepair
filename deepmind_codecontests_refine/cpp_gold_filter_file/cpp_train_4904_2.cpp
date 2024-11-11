#include <bits/stdc++.h>
using namespace std;
int gcd(int(a), int(b)) {
  int r;
  while (b > 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int sum = n * (n + 1) / 2;
  if (n == 1 || n == 2)
    cout << "No";
  else {
    cout << "Yes" << endl;
    for (int i = 1; i <= n; ++i) {
      if (gcd(i, sum - i) > 1) {
        cout << 1 << " " << i << endl;
        cout << n - 1;
        for (int j = 1; j <= n; ++j) {
          if (j != i) cout << " " << j;
        }
        break;
      }
    }
  }
  return 0;
}

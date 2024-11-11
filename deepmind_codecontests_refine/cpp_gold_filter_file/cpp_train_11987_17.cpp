#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, f = 0, g;
  cin >> a >> b;
  c = b * (b - 1);
  if (c < a) {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;
  for (int k = 1; k <= a; k++) {
    for (int i = 1; i <= b; i++) {
      for (int j = i + 1; j <= b; j++) {
        if (i != j) {
          cout << i << " " << j << endl;
          f++;
        }
        if (f == a) {
          return 0;
        }
        if (j != i) {
          cout << j << " " << i << endl;
          f++;
        }
        if (f == a) {
          return 0;
        }
      }
    }
  }
}

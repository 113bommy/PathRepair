#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b, n, c = 0;
    cin >> a >> b >> n;
    int t1 = max(a, b), t2 = min(a, b);
    while (t1 > n) {
      int temporary = t1;
      t1 += t2;
      t2 = temporary;
      c++;
    }
    cout << c << "\n";
  }
  return 0;
}

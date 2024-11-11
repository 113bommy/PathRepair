#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, t, c, count = 0;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t == 1 && a > 0)
      a--;
    else if (t == 1 && b > 0) {
      b--;
      c++;
    } else if (t == 1 && a == 0 && b == 0 && c > 0)
      c--;
    else if (t == 1 && a == 0 && b == 0 && c == 0)
      count++;
    else if (t != 1 && b > 0)
      b--;
    else if (t != 1 && b == 0)
      count += 2;
  }
  cout << count << endl;
  return 0;
}

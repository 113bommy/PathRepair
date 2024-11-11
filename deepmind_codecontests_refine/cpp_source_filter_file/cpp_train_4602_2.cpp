#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, m, p;
  cin >> t;
  while (t--) {
    int e1 = 0, o1 = 0, e2 = 0, o2 = 0;
    cin >> n;
    while (n--) {
      cin >> p;
      if (p % 2)
        o1++;
      else
        e1++;
    }
    cin >> m;
    while (m--) {
      cin >> p;
      if (p % 2)
        o2++;
      else
        e2++;
    }
    cout << e1 * e2 + o1 * o2 << endl;
  }
}

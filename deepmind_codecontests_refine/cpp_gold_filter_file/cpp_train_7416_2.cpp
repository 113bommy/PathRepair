#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int count = 0;
    if (n < 2)
      cout << "0" << endl;
    else {
      int x = 0, p = 0, i = 0;
      while (n >= x) {
        i++;
        x += (i * 2) + p;
        p++;
      }
      i--;
      while (i != 0) {
        int k = i * (i + 1) + (i - 1) * (i) / 2;
        if (k <= n) {
          count++;
          n -= k;
        } else
          i--;
        if (n < 2 && i == 0) break;
      }
      cout << count << endl;
    }
  }
  return 0;
}

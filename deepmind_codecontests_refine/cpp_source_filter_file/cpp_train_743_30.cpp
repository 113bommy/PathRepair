#include <bits/stdc++.h>
using namespace std;
int main() {
  int pos, len;
  int n, k, m, t;
  cin >> n >> k >> m >> t;
  pos = k;
  len = n;
  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    if (a == 0) {
      if (b < k) {
        pos -= b;
        len -= b;
      } else {
        len = b;
      }
    } else {
      if (b <= pos) {
        pos++;
        len++;
      } else {
        len++;
      }
    }
    cout << len << " " << pos << '\n';
  }
  return 0;
}

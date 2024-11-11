#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p = 0, q = 0, max1 = INT_MIN, k, m, s = 0;
  cin >> n;
  while (n--) {
    s = 0;
    cin >> m >> k;
    s = s + q - m;
    s = s + k;
    max1 = max(max1, s);
    q = k;
  }
  cout << max1 << endl;
}

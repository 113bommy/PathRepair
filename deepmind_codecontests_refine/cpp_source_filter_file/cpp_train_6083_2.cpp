#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, p, a = 1, b = 2;
    cin >> n >> p;
    int z = n + n;
    while (z--) {
      cout << a << " " << b << endl;
      b++;
      if (b == n + 1) {
        a++;
        b = a + 1;
      }
    }
  }
  return 0;
}

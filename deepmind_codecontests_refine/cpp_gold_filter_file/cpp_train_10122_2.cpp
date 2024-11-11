#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    int arr[n], x, s = 0, cnt = 0;
    if (n == m)
      cout << 0 << endl;
    else if (n < m) {
      int a = m - n;
      if (a % 2 != 0)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    } else {
      int b = n - m;
      if (b % 2 == 0)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
  return 0;
}

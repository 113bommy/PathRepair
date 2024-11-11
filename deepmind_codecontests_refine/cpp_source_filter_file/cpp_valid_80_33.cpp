#include <bits/stdc++.h>
using namespace std;
int t, n, a[20004], l;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    l = 0;
    getchar();
    for (int i = 1; i <= n; i++) {
      a[i] = getchar() - '0';
      if (l == 0 && a[i] == 0) l = i;
    }
    if (n == 1)
      cout << "1 1 1 1" << endl;
    else if (l == 0)
      cout << 1 << " " << n / 2 << " " << n - n / 2 + 1 << " " << n << endl;
    else {
      if (n - l + 2 >= n / 2)
        cout << l << " " << n << " " << l + 1 << " " << n << endl;
      else
        cout << 1 << " " << l << " " << 1 << " " << l - 1 << endl;
    }
  }
  return 0;
}

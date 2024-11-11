#include <bits/stdc++.h>
using namespace std;
long long n, m, minp, t;
int main() {
  cin >> n >> m;
  minp = 999999937;
  cout << minp << " " << minp << endl;
  cout << "1 2 " << minp - n + 1 << endl;
  for (int i = 1; i < n - 1; i++) {
    cout << i + 1 << " " << i + 2 << " " << 1 << endl;
  }
  t = n - 1;
  for (int i = 1; i < n; i++) {
    for (int j = i + 2; j <= n; j++) {
      t++;
      if (t > m) return 0;
      if (i == 1) {
        cout << i << " " << j << " " << minp - n + 1 + (j - i) << endl;
      } else {
        cout << i << " " << j << " " << j - i << endl;
      }
    }
  }
}

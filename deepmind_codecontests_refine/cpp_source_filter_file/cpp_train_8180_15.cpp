#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  if (n % 4 == 2 || n % 4 == 3)
    puts("NO");
  else {
    puts("YES");
    for (long long i = 1; i < n; i++) {
      for (long long j = i + 2; j < n; j++) {
        cout << i << " " << j << endl;
        cout << i + 1 << " " << j + 1 << endl;
        cout << i << " " << j + 1 << endl;
        cout << i + 1 << " " << j << endl;
      }
      if (n % 4 == 1) {
        cout << i << " " << n << endl;
        cout << i << " " << i + 1 << endl;
        cout << i + 1 << " " << n << endl;
      } else
        cout << i << " " << i + 1 << endl;
    }
  }
}

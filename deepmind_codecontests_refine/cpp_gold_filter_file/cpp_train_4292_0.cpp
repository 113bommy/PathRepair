#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[3] = {}, count = 0;
    for (long long i = 2; i * i < n; i++) {
      if (n % i == 0) {
        a[count] = i;
        count++;
        n /= i;
      }
      if (count >= 2) break;
    }
    if (count != 2)
      cout << "NO\n";
    else {
      cout << "YES\n";
      cout << a[0] << " " << a[1] << " " << n << endl;
    }
  }
}

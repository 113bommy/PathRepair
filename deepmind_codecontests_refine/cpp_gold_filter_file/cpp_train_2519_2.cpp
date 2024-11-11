#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, n, s;
    cin >> a >> b >> n >> s;
    if ((s / n) < a) {
      if (s - ((s / n) * n) > b)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    } else {
      if (s - (n * a) > b)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
  }
}

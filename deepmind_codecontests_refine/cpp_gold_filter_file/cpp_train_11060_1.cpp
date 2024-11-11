#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 4)
      cout << "NO" << endl;
    else {
      vector<long long int> o;
      vector<long long int> e;
      for (long long int i = 1; i <= n + 1; i++) {
        if (i != n / 2 + 1) {
          if (i & 1)
            o.push_back(i);
          else
            e.push_back(i);
        }
      }
      cout << "YES" << endl;
      for (long long int i = 0; i < n; i++) {
        if (i < n / 2)
          cout << e[i] << ' ';
        else
          cout << o[i - n / 2] << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, d, e, i, j, k, l;
    cin >> a;
    vector<long long> v;
    for (i = 1; i <= a; i++) {
      cin >> b;
      if (i == 1)
        l = b;
      else
        l = max(l, b);
      v.push_back(b);
    }
    j = 0;
    for (i = 0; i < a; i++) {
      if (v[i] == l) {
        if (i == 0 && v[i + 1] < v[i]) {
          cout << i + 1 << endl;
          j = 1;
          break;
        } else if (i == a - 1 && v[i] > v[i - 1]) {
          cout << i + 1 << endl;
          j = 1;
          break;
        } else if (i != 0 && i + 1 < a) {
          if (v[i] > v[i + 1]) {
            cout << i + 1 << endl;
            j = 1;
            break;
          }
          if (v[i] > v[i - 1]) {
            cout << i + 1 << endl;
            j = 1;
            break;
          }
        }
      }
    }
    if (j == 0) cout << -1 << endl;
  }
}

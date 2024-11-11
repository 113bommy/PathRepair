#include <bits/stdc++.h>
using namespace std;
const long long maxi = 100001;
const long long inf = 1e16;
const long long ninf = 1e16 * (-1);
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v;
    vector<vector<long long>> w;
    for (long long i = 0; i < n; i++) {
      v.push_back(1);
    }
    for (long long i = n; i < 2 * n; i++) {
      v.push_back(0);
    }
    w.push_back(v);
    for (long long i = 1; i < n; i++) {
      for (long long j = n - i; j < 2 * n - 1; j += 2) {
        swap(v[j], v[j + 1]);
      }
      w.push_back(v);
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < 2 * n; j++) {
        if (w[i][j] == 1) {
          cout << "(";
        } else {
          cout << ")";
        }
      }
      cout << endl;
    }
  }
}

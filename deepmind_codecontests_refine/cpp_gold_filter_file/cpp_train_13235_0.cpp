#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
signed main() {
  long long h, w;
  cin >> h >> w;
  vector<vector<long long>> a(h, vector<long long>(w)),
      b(h, vector<long long>(w));
  for (long long i = 0; i < h; i++) {
    for (long long j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  for (long long i = 0; i < h; i++) {
    for (long long j = 0; j < w; j++) {
      cin >> b[i][j];
    }
  }
  for (long long i = 0; i < h; i++) {
    long long sum = 0;
    for (long long j = 0; j < w; j++) sum += a[i][j] + b[i][j];
    if (sum % 2 == 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  for (long long i = 0; i < w; i++) {
    long long sum = 0;
    for (long long j = 0; j < h; j++) sum += a[j][i] + b[j][i];
    if (sum % 2 == 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}

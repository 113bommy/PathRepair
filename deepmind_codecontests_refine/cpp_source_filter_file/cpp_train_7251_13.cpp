#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  while (t--) {
    long long n, s, i, j, k;
    string str;
    cin >> n >> s;
    long long h[n], m[n];
    for (i = 0; i < n; i++) {
      cin >> h[i] >> m[i];
      m[i] += 60 * h[i];
    }
    if (m[0] > s + 2) {
      long long H = 0;
      long long M = 0;
      cout << H << " " << M;
      return 0;
    }
    for (i = 1; i < n; i++) {
      if (m[i] - m[i - 1] > 2 * s + 2) {
        break;
      }
    }
    long long H = (m[i - 1] + s + 1) / 60, M = (m[i - 1] + s + 1) % 60;
    cout << H << " " << M;
  }
  return 0;
}

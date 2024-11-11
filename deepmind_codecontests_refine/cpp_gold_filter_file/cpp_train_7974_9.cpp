#include <bits/stdc++.h>
using namespace std;
const int maxInt = 1e9 * 2;
const long long int maxLong = 1e18 * 2;
int ln[55], col[55];
int main() {
  int n, m;
  cin >> n >> m;
  long long int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool ch;
      cin >> ch;
      if (ch) {
        ln[i]++;
        col[j]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cnt += (1LL * 1 << ln[i]) - 1;
    cnt += (1LL * 1 << m - ln[i]) - 1;
  }
  for (int j = 0; j < m; j++) {
    cnt += (1LL * 1 << col[j]) - 1;
    cnt += (1LL * 1 << n - col[j]) - 1;
  }
  cout << cnt - m * n;
}

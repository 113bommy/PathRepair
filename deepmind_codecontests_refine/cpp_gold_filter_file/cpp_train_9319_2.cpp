#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
long long a[1500];
long long b[1500];
long long ai[1500];
long long bi[1500];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  long long maxx = 0;
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < n; ++y) {
      long long c1 = 0, c2 = 0;
      for (int k = x; k <= y; ++k) {
        c1 |= a[k];
        c2 |= b[k];
      }
      maxx = max(c1 + c2, maxx);
    }
  }
  cout << maxx << endl;
  return 0;
}

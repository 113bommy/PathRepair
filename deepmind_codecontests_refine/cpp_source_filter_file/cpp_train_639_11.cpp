#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long p[m];
  long long s = 0;
  for (int i = 0; i < m; i++) {
    cin >> p[i];
    p[i]--;
  }
  long long t, x, y = 0;
  bool q = 0;
  for (int i = 0; i < m; i++) {
    if (p[i] - t > y) {
      q = 0;
    }
    if (q == 0) {
      s++;
      q = 1;
      t = i;
      x = p[i] - i - ((p[i] - i) % k);
      y = x + k;
    }
  }
  cout << s;
  return 0;
}

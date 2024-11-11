#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000001;
int a[6], b[6];
int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= min(m, 5); i++) {
    a[i]++;
    int c = i;
    while (c + 5 <= m) {
      c += 5;
      a[i]++;
    }
  }
  for (int i = 1; i <= min(n, 5); i++) {
    b[i]++;
    int c = i;
    while (c + 5 <= n) {
      c += 5;
      b[i]++;
    }
  }
  long long s = 0;
  for (int i = 1; i <= 5; i++) {
    s += a[i] * b[5 - i];
  }
  if (m >= 5 && n >= 5) s += a[5] * b[5];
  cout << s << endl;
}

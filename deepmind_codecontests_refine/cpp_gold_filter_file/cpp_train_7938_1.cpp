#include <bits/stdc++.h>
using namespace std;
long long ask(long long a, long long b) {
  cout << "?" << a + 1 << " " << b + 1 << endl;
  long long k;
  cin >> k;
  return k;
}
int main() {
  long long n, m, x1, y1;
  cin >> n >> m >> x1 >> y1;
  cout << x1 << " " << y1 << endl;
  vector<long long> v1(m + 1, 0), v2(n + 1, 0);
  v1[y1] = 1;
  for (int i = 1; i < m + 1; i++) {
    if (v1[i] == 1)
      v1[i] = 0;
    else
      cout << x1 << " " << i << endl;
  }
  if (y1 == n)
    v1[y1 - 1] = 1;
  else
    v1[y1] = 1;
  v2[x1] = 1;
  long long k = 0;
  for (int i = 1; i < n + 1; i++) {
    if (v2[i]) continue;
    if (k == 1) {
      for (int j = 1; j < m + 1; j++) {
        cout << i << " " << j << endl;
      }
      k = 0;
    } else {
      for (int j = m; j >= 1; j--) {
        cout << i << " " << j << endl;
      }
      k = 1;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const long long inf = 2000000000000000007LL;
int n, m, a[N], b[N];
void gen(int *a, int n) {
  if (n == 1)
    a[0] = 1;
  else if (n == 2)
    a[0] = 3, a[1] = 4;
  else {
    if (n & 1) {
      for (int i = 0; i < n - 1; i++) a[i] = 2;
      a[n - 1] = n - 2;
    } else {
      for (int i = 0; i < n - 1; i++) a[i] = 3;
      a[n - 1] = (9 * n - 10) / 2;
    }
  }
}
int main() {
  cin >> n >> m;
  gen(a, n);
  gen(b, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << a[i] * b[j] << " ";
    cout << endl;
  }
  return 0;
}

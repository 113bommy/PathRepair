#include <bits/stdc++.h>
using namespace std;
long c[10004];
int n, d;
long x[500005];
int z[600004];
int main() {
  cin >> n >> d;
  long s = 0;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    s = s + c[i];
  }
  sort(c + 1, c + n + 1);
  x[c[1]] = 1;
  x[0] = 1;
  for (long i = 2; i <= n; i++) {
    for (long j = s; j >= c[i]; j--) {
      if (x[j] == 0) x[j] = x[j - c[i]];
    }
  }
  z[0] = 0;
  for (long i = 1; i <= s; i++) {
    if (x[i] == 1) {
      z[i] = i;
    } else
      z[i] = z[i - 1];
  }
  for (long i = s + 1; i <= s + 2 * d; i++) z[i] = z[s];
  int e = 0;
  long l = 0;
  long h = 0;
  long p = d;
  while (e == 0) {
    long f = z[p];
    if (f == h) {
      e = 1;
    } else {
      h = f;
      p = h + d;
      l++;
    }
  }
  cout << h << " " << l << endl;
}

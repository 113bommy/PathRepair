#include <bits/stdc++.h>
using namespace std;
unsigned long long m, n, i, t, k, a[1000];
int main() {
  cin >> m;
  t = 1;
  k = 1;
  for (i = 0; i < m; i++) {
    cin >> a[i];
  }
  sort(a, a + m);
  for (i = 0; i < m; i++) {
    if (a[i] == a[i + 1])
      k = k + 1;
    else {
      if (t <= k)
        t = k;
      else
        t = t;
      k = 1;
    }
  }
  cout << t;
}

#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, y, i, j, l, r, t, a[456], d;
set<long long> s;
set<long long>::reverse_iterator it;
char c;
int main() {
  cin >> n >> d;
  for (i = 0; i < d; i++) {
    for (j = 0; j < n; j++) {
      cin >> c;
      if (c == '1') a[i]++;
    }
  }
  a[d] = n;
  for (i = 0; i <= d; i++) {
    if (a[i] == n) continue;
    t = 1;
    while (a[i + 1] < n && i + 1 < d) {
      t++;
      i++;
    }
    m = max(m, t);
  }
  cout << m;
}

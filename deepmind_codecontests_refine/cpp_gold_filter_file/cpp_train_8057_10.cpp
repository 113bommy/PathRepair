#include <bits/stdc++.h>
using namespace std;
int n, m;
long long h[100000], p[100000];
bool F(long long x) {
  int pp = 0;
  int a = 0;
  int b = 0;
  while ((pp < n) && (a < m)) {
    b = a;
    while (
        (min(abs(h[pp] - p[b]), abs(h[pp] - p[a])) + abs(p[a] - p[b]) <= x) &&
        (a < m)) {
      a++;
    }
    pp++;
  }
  if (a == m) {
    return true;
  } else {
    return false;
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> p[i];
  }
  long long k = 10000000000;
  long long st = 5000000000;
  while ((!(F(k) && !(F(k - 1))) && (k >= 0))) {
    if (F(k)) {
      k -= st;
    } else {
      k += st;
    }
    st = max(st / 2, 1ll);
  }
  if (k < 0) {
    k = 0;
  }
  cout << k;
  return 0;
}

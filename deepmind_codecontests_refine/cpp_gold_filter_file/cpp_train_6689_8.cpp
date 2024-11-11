#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int f[N], g[N], a[N + 1], b[N + 1];
int get(long long s, long long e) {
  if (2 * s > e) {
    return 1;
  } else {
    e /= 2;
    if (e & 1) {
      return (e - s) & 1;
    } else if (2 * s > e) {
      return (e - s) & 1;
    } else {
      return get(s, e / 2);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = (1); i < (n + 1); i++) {
    long long s, e;
    cin >> s >> e;
    f[i] = get(s, 2 * e);
    g[i] = get(s, e);
  }
  b[1] = 1;
  for (int i = (1); i < (n + 1); i++) {
    if (f[i])
      a[i + 1] = b[i];
    else
      a[i + 1] = a[i];
    if (g[i])
      b[i + 1] = b[i];
    else
      b[i + 1] = a[i];
  }
  cout << a[n + 1] << " " << b[n + 1] << "\n";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
long long v[100], n;
int T, i;
void precalc() {
  long long x = 1;
  v[0] = 1;
  while (1LL * x * 3 < 1LL * INF) {
    x *= 3;
    v[++i] = x;
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> T;
  precalc();
  for (; T--;) {
    cin >> n;
    int j;
    long long x = 0;
    for (j = 0; j <= i; j++)
      if (x < n) x += v[j];
    while (j >= 0) {
      if (x - v[j] >= n) x -= v[j];
      j--;
    }
    cout << x << '\n';
  }
}

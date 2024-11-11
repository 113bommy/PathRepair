#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int t, n, a[N], b[N];
long long arie;
long long mo(long long q) { return q > 0 ? q : -q; }
long long calc(int a1, int b1, int a2, int b2, int a3, int b3) {
  return 1LL * a1 * b2 + 1LL * a2 * b3 + 1LL * a3 * b1 - 1LL * b2 * a3 -
         1LL * b3 * a1 - 1LL * b1 * a2;
}
bool ver(int aa, int bb) {
  int i, nr = 0;
  long long ar = 0;
  for (i = 1; i <= n; ++i) {
    ar += mo(calc(aa, bb, a[i], b[i], a[i + 1], b[i + 1]));
  }
  if (ar != arie) return 0;
  return 1;
}
long long count(int x, int y) {
  if (!ver(x, y)) return -1;
  int i, j = 2;
  long long re = 0;
  for (i = 1; i <= n; ++i) {
    j = max(j, i + 1);
    while (j < i + n && calc(a[i], b[i], a[j], b[j], x, y) < 0) ++j;
    re += 1LL * (j - i - 1) * (j - i - 2) / 2;
  }
  return re;
}
int main() {
  int i;
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    if (i != 1) arie += 1LL * (a[i] + a[i - 1]) * (b[i] - b[i - 1]);
  }
  arie += 1LL * (a[n] + a[1]) * (b[1] - b[n]);
  for (i = n + 1; i <= 2 * n; ++i) {
    a[i] = a[i - n];
    b[i] = b[i - n];
  }
  if (arie < 0) arie = -arie;
  cin >> t;
  for (i = 1; i <= t; ++i) {
    int a, b;
    cin >> a >> b;
    long long re = 1LL * n * (n - 1) * (n - 2) / 2 / 3, aa = count(a, b);
    if (aa == -1) {
      cout << "0\n";
      continue;
    }
    cout << re - aa << "\n";
  }
  return 0;
}

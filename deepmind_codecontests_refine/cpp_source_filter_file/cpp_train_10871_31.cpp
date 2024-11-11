#include <bits/stdc++.h>
using namespace std;
ifstream fin;
ofstream fout;
FILE *outt, *inn;
const int N = 1000009, M = 1002;
int n, m, a[M], b[M], ans = 2147483647, first, p;
int solve(int x) {
  for (int i = 1; i <= n; i++) {
    b[i] = a[i] - (i - 1) * x;
  }
  sort(b + 1, b + n + 1);
  int d = (abs(b[1] - b[n]) + 1) / 2;
  if (d < ans) {
    ans = d;
    first = b[1] + d;
    p = x;
  }
  return d;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int l = 0, r = 1e8, m1, m2;
  while ((r - l) > 3) {
    m = (r - l) / 3;
    m1 = solve(l + m);
    m2 = solve(r - m);
    if (m1 < m2) {
      r -= m;
    } else {
      l += m;
    }
  }
  for (int i = l; i <= r; i++) {
    m = solve(i);
  }
  cout << ans << endl;
  cout << first << " " << p;
  return 0;
}

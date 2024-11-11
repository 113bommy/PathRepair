#include <bits/stdc++.h>
using namespace std;
void solve(istream &in, ostream &out) {
  int n, m, k, a[101000], b[101000];
  in >> n >> m >> k;
  for (int i = 0; i < n; i++) in >> a[i];
  for (int i = 0; i < m; i++) in >> b[i];
  sort(a, a + n);
  reverse(a, a + n);
  sort(b, b + m);
  reverse(b, b + m);
  int p = -1;
  for (int i = 0; i < min(n, m); i++)
    if (a[i] > b[i]) p = i;
  if (n >= m and p != -1)
    puts("YES");
  else
    puts("NO");
}
int main() {
  solve(cin, cout);
  return 0;
}

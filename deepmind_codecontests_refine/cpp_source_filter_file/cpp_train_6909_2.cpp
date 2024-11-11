#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200200];
int f(int x) { return ((x % n) + n) % n; }
int main() {
  scanf("%d%d", &n, &m);
  m--;
  for (int i = (0); i < (n); i++) cin >> a[i];
  int p = m;
  for (int i = (0); i < (n); i++)
    if (a[p] >= a[f(p + i)]) p = f(p + i);
  long long tmp = a[p] * n + f(m - p);
  for (int i = (0); i < (n); i++)
    if (i != p) a[i] -= a[p];
  for (int i = (0); i < (n); i++) {
    a[f(i + p)]--;
    if (f(i + p) == m) break;
  }
  a[p] = tmp;
  cout << a[0];
  for (int i = (1); i < (n); i++) cout << " " << a[i];
  puts("");
  return 0;
}

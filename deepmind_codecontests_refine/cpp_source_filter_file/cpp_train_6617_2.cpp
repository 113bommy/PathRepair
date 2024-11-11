#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 100;
int n, n1, n2, a[N], s1, s2;
double ave1, ave2, avet;
int main() {
  cin >> n >> n1 >> n2;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n1 > n2) swap(n1, n2);
  sort(a + 1, a + n + 1);
  for (int i = n; i >= n - n1 + 1; i--) s1 += a[i];
  for (int i = n - n1; i >= n - n1 - n2 + 1; i--) s2 += a[i];
  ave1 = (double)s1 / (double)n1;
  ave2 = (double)s2 / (double)n2;
  cout << setprecision(10) << fixed << ave1 + ave2;
  return 0;
}

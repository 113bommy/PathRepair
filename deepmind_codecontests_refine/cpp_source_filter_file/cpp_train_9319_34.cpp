#include <bits/stdc++.h>
using namespace std;
int f(int *a, int r, int l) {
  int s = 0;
  for (int i = r; i <= l; i++) s = s | a[i];
  return s;
}
int a[1005], b[1005], m, n, r, A, B;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++)
    for (int j = n - 1; j > i; j--) {
      A = f(a, i, j);
      B = f(b, i, j);
      r = A + B;
      m = max(m, r);
    }
  cout << m;
  return 0;
}

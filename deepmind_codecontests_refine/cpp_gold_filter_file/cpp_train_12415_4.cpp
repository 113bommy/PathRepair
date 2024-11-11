#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N];
int b[N];
int n;
int c[2 * N];
int mex() {
  memset(b, 0, sizeof(b));
  for (int i = 0; i < n; i++) b[a[i]]++;
  for (int i = 0; i <= n; i++)
    if (b[i] == 0) return i;
}
bool check() {
  for (int i = 0; i < n - 1; i++)
    if (a[i] > a[i + 1]) return false;
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int tol = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    while (1) {
      int m = mex();
      if (m < n) {
        a[m] = m;
        c[tol++] = m;
      } else {
        for (int i = 0; i < n; i++)
          if (a[i] != i) {
            a[i] = m;
            c[tol++] = i;
            break;
          }
      }
      if (check()) break;
    }
    cout << tol << endl;
    for (int i = 0; i < tol; i++) cout << c[i] + 1 << ' ';
    cout << endl;
  }
  return 0;
}

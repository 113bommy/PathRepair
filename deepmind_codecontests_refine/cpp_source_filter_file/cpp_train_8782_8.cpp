#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100003], q[100003];
void nhap() {
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> q[i];
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
}
void xuli() {
  sort(a + 1, a + n + 1);
  sort(q + 1, q + m + 1);
  int sl = q[1];
  int kq = 0;
  for (int i = n; i >= 1; i--) {
    if (q[sl] == 0) {
      sl = q[1];
      i -= 2;
    }
    kq += a[i];
    sl--;
  }
  cout << kq;
}
int main() {
  nhap();
  xuli();
}

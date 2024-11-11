#include <bits/stdc++.h>
using namespace std;
int a[3];
long long kq;
void nhap() { cin >> a[0] >> a[1] >> a[2]; }
void cbi() { sort(a, a + 3); }
void xuli() {
  if (a[0] == a[1] && a[1] == a[2]) {
    cout << a[0];
    exit(0);
  }
  if (a[0] + a[1] < a[2] / 2)
    kq = 1ll * a[0] + a[1];
  else
    kq = 1ll * (a[0] + a[1] + a[2]) / 3;
}
void ghikq() { cout << kq; }
int main() {
  nhap();
  cbi();
  xuli();
  ghikq();
  return 0;
}

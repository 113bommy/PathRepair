#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  int a;
  int b;
  int c;
  int d;
  cin >> n >> a >> b >> c >> d;
  int kol = 0;
  int vop1 = 1;
  int vop2;
  int vop3;
  int vop4;
  while (vop1 <= n) {
    vop2 = vop1 + b - c;
    vop3 = vop1 + b - c + a - d;
    vop4 = vop1 + a - d;
    if (vop2 > 0 && vop2 < n + 1 && vop3 > 0 && vop3 < n + 1 && vop4 > 0 &&
        vop4 < n + 1)
      kol++;
    vop1++;
  }
  cout << kol * n;
}

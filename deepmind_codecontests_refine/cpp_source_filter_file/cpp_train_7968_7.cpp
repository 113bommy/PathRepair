#include <bits/stdc++.h>
using namespace std;
int a, n;
long long b, c;
int main() {
  scanf("%d", &a);
  long long n = 1ll * a * a;
  if (a & 1) {
    b = (n - 1) / 2;
    a = b + 1;
  } else {
    b = (n - 4) / 4;
    a = b + 2;
  }
  if (b < 0 || a < 0)
    cout << -1;
  else
    cout << b << " " << a;
}

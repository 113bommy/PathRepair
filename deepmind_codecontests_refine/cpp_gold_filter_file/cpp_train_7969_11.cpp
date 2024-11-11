#include <bits/stdc++.h>
using namespace std;
int a;
long long b, c;
int main() {
  scanf("%d", &a);
  long long n = 1ll * a * a;
  if (a & 1) {
    b = (n - 1) / 2;
    c = b + 1;
  } else {
    b = (n - 4) / 4;
    c = b + 2;
  }
  if (b <= 0 || c <= 0)
    cout << -1;
  else
    cout << b << " " << c;
}

#include <bits/stdc++.h>
using namespace std;
int q;
long long n, a, b;
int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%I64d%I64d%I64d", &n, &a, &b);
    if (a <= b / 2)
      cout << a * n << endl;
    else {
      if (n & 1)
        cout << a + (n / 2) * b << endl;
      else
        cout << b * (n / 2) << endl;
    }
  }
  return 0;
}

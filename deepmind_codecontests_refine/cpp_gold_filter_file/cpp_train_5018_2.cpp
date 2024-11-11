#include <bits/stdc++.h>
using namespace std;
long long int __xor(long long int a, long long int b) { return a ^ b; }
long long int __and(long long int a, long long int b) { return a & b; }
long long int __or(long long int a, long long int b) { return a | b; }
long long int ai[1000], pi[1000];
int main() {
  long long int a, b, c = 0, x, y, z, t, i, j, k, l1, l2, m, n, c1 = 0, c2 = 0,
                      q;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &a);
    scanf("%lld", &b);
    l1 = abs(a - b);
    while (l1 != 0) {
      if (l1 >= 5) {
        c += l1 / 5;
        l1 = l1 % 5;
      } else if (l1 >= 2) {
        c += l1 / 2;
        l1 = l1 % 2;
      } else {
        c += l1 / 1;
        l1 = l1 % 1;
      }
    }
    cout << c << "\n";
    c = 0;
  }
  return 0;
}

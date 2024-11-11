#include <bits/stdc++.h>
using namespace std;
long long n, num, sol, bas;
char A[100000];
int bus(int p) {
  num = 0ll, bas = 1ll;
  while (p >= 0ll) {
    if (num + 1ll * (A[p] - 48) * bas >= n) return p;
    num = num + 1ll * (A[p] - 48) * bas;
    bas *= 10ll;
    p--;
    if (bas >= n) return p;
  }
  return p;
}
int main() {
  scanf("%lld %s", &n, A);
  int la = strlen(A);
  long long bas1 = 1ll;
  for (int i = la - 1; i >= 0;) {
    int pos = bus(i);
    while (pos < i - 1 && A[pos + 1] == '0') pos++;
    i = pos;
    sol = sol + bas1 * num;
    bas1 *= n;
  }
  printf("%lld\n", sol);
  return 0;
}

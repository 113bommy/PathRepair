#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T sqr(T a) {
  return a * a;
}
int main() {
  long long n;
  scanf("%I64d", &n);
  printf("%I64d", 6 * n * (n - 1) + 1);
  return 0;
}

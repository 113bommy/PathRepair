#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T sqr(T a) {
  return a * a;
}
int main() {
  long long n;
  scanf("%I64d", &n);
  printf("%I64d", 3 * n * (n + 1) - 5);
  return 0;
}

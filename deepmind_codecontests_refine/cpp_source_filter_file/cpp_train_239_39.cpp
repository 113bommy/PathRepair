#include <bits/stdc++.h>
using namespace std;
bool g(long long base, long long n) {
  if (base & 1) {
    long long tmp = 0;
    while (n) {
      tmp += n % base;
      n /= base;
    }
    return tmp % 2 == 1;
  } else {
    return (n % (base + 1)) % 2 == 0;
  }
}
bool win(long long mi, long long ma) {
  if (!mi) return 0;
  if (!win(ma % mi, mi)) return 1;
  return g(mi, ma / mi);
}
int main() {
  int i, j, k, n, t;
  long long a, b;
  scanf("%d", &t);
  while (t--) {
    cin >> a >> b;
    if (win(min(a, b), max(a, b)))
      printf("First\n");
    else
      printf("Second\n");
  }
  return 0;
}

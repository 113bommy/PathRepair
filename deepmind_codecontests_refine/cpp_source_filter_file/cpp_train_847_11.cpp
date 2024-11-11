#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:256000000")
template <typename T>
int size(T& a) {
  return (int)a.size();
}
template <typename T>
T sqr(T a) {
  return a * a;
}
int main() {
  int a, b, mod;
  cin >> a >> b >> mod;
  int ta = a, tb = b;
  a %= mod;
  b %= mod;
  a += mod;
  b += mod;
  a = min(a, ta);
  b = min(b, tb);
  int r = 1;
  for (int i = (0); i < (10); ++i) r = (r * 10) % mod;
  for (int i = 0; i <= a; ++i) {
    int c = (long long)r * i % mod;
    int z = (mod - c);
    if (z >= mod) z -= mod;
    if (z <= b) {
      continue;
    }
    printf("1 ");
    printf("%0*d", 9, i);
    return 0;
  }
  printf("2");
}

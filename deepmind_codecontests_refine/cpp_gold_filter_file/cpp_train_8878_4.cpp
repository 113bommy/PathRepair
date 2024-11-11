#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
namespace std {
bool operator<(const complex<double>& a, const complex<double>& b) {
  return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}
}  // namespace std
char s[123];
int mask(int a) {
  int m = 0;
  int pot = 1;
  while (a) {
    if (a % 10 == 4 || a % 10 == 7) {
      m = (a % 10) * pot + m;
      pot *= 10;
    }
    a /= 10;
  }
  return m;
}
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  a++;
  while (mask(a) != b) {
    a++;
  }
  printf("%d\n", a);
  return 0;
}

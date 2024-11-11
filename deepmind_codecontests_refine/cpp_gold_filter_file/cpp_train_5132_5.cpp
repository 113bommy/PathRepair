#include <bits/stdc++.h>
using namespace std;
inline void error(int n) { cout << fixed << setprecision(n + 1); }
inline long long gcd(long long a, long long b) {
  return (a ? gcd(b % a, a) : b);
}
inline bool is_prime(long long n) {
  for (long long i = 2; i * i <= n; i++)
    if (!(n % i)) return false;
  return (n > 1);
}
int n_4 = 0, n_7 = 0, l, i;
char a[1000000], b[1000000];
int main() {
  scanf("%s%s", &a, &b);
  l = strlen(a);
  for (i = (0); i <= (l); i++)
    if (a[i] != b[i]) {
      if (a[i] == '4')
        n_4++;
      else
        n_7++;
    }
  printf("%d", max(n_4, n_7));
}

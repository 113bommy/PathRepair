#include <bits/stdc++.h>
using namespace std;
int tab[50000];
int main() {
  int t;
  int long long n, a, b, c, maxi;
  scanf("%lld", &t);
  while (t--) {
    int s = 0;
    int long long i = 2, j = 2, sq;
    scanf("%lld", &n);
    sq = sqrt(n);
    while (n != 0 && i <= sq) {
      if (n % i == 0) {
        tab[s] = i;
        s++;
        if (s == 2) break;
        n /= i;
      }
      i++;
    }
    if (s == 2 && n / i >= (i + 1)) {
      printf("YES\n%d %d %d\n", tab[0], tab[1], n / i);
    } else
      printf("NO\n");
  }
}

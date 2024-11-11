#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6005;
int a[MAXN];
bool isprime(int n) {
  int len = sqrt(n * 1.0);
  for (int i = 2; i <= len; i++)
    if (n % i == 0) return false;
  return true;
}
int main() {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; i++) a[i] = 1;
    int m = (n + 1) * n / 2;
    if (!isprime(m)) {
      if (m % 2 == 0) {
        int p = -1;
        for (int i = 2; i <= n; i++)
          if (isprime(i) && isprime(m - i)) {
            p = i;
            a[i] = 2;
            break;
          }
      } else {
        if (isprime(m - 2)) {
          a[2] = 2;
        } else {
          a[3] = 2;
          m -= 3;
          for (int i = 2; i <= n; i++)
            if (isprime(i) && isprime(m - i)) {
              a[i] = 3;
              break;
            }
        }
      }
    }
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
  }
  return 0;
}

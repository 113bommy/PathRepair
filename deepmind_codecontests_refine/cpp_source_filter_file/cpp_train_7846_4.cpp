#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
void __never(int a) { printf("\nOPS %d", a); }
long long n;
void sol() {
  if (n % 3 != 0) {
    cout << 0;
    return;
  }
  n /= 3;
  long long ans = 0;
  for (long long a = 1; a * a * a <= n; a++)
    if (n % a == 0) {
      long long nn = n / a;
      long long bb = (long long)(sqrt((double)nn + 5));
      while (bb * bb > n) bb--;
      for (long long b = bb; b >= a; b--)
        if (nn % b == 0) {
          long long c = nn / b;
          if (a + b <= c) break;
          if (((a + b + c) & 1) == 0) {
            long long p = (a + b + c) / 2;
            long long pa = p - a, pb = p - b, pc = p - c;
            if (pa > 0 && pb > 0 && pc > 0) {
              if (pa != pb && pa != pc && pb != pc)
                ans += 6;
              else if (pa == pb && pa == pc)
                ans++;
              else
                ans += 3;
            }
          }
        }
    }
  cout << ans;
}
int main() {
  cin >> n;
  sol();
  return 0;
}

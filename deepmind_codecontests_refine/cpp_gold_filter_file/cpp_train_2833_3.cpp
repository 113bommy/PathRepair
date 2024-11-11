#include <bits/stdc++.h>
using namespace std;
char a[1000005];
void f() {
  long long i, j;
  long long l = 0;
  long long x;
  cin >> x;
  cin >> a + 1;
  const long long D = 1e9 + 7;
  long long n = strlen(a + 1);
  for (i = 1; i <= n; i++) a[i] -= '0';
  long long m = n;
  int isok = 1;
  while (1) {
    l++;
    if (isok) {
      for (i = m + 1; i <= x && i <= m + (m - l) * (a[l] - 1); i++)
        a[i] = a[i - m + l];
    }
    if (isok == 0) {
      m += (m - l + D) % D * (a[l] - 1) % D;
      m %= D;
    } else {
      m += (m - l) * (a[l] - 1);
      if (m > x) isok = 0;
      m %= D;
    }
    if (l == x) {
      cout << m << "\n";
      return;
    }
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) f();
  return 0;
}

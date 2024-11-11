#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int maxn = 1000001;
bool p[maxn];
int xdiv[maxn];
int divs[maxn];
void sieve() {
  memset(p, true, sizeof p);
  p[0] = p[1] = false;
  for (int i = 2; i <= 1000; ++i)
    if (p[i])
      for (int j = i * i; j < maxn; j += i) {
        if (p[j]) {
          p[j] = false;
          xdiv[j] = i;
        }
      }
  divs[0] = 0;
  divs[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    if (p[i]) {
      divs[i] = 2;
    } else {
      int m = i;
      int cnt = 0;
      while (m % xdiv[i] == 0) cnt++, m /= xdiv[i];
      divs[i] = divs[m] * (cnt + 1);
    }
  }
}
int a[10];
int f(int a) {
  a %= 9;
  if (a == 0) a = 9;
  return a;
}
int main() {
  sieve();
  memset(a, 0, sizeof a);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) a[f(i)]++;
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    int cnt = divs[i];
    long long ff = 0;
    int dig = f(i);
    for (int j = 1; j < 10; ++j)
      for (int k = 1; k < 10; ++k)
        if (dig == f(j * k)) {
          long long c1 = a[j], c2 = a[k];
          ff += c1 * c2;
        }
    res += ff - cnt;
  }
  cout << res << endl;
  return 0;
}

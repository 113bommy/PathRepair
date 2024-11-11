#include <bits/stdc++.h>
long long t, a, b, h, f[110];
using namespace std;
long long mi(long long n, long long m) {
  long long res = 1;
  for (int i = 1; i <= m; i++) res *= n;
  return res;
}
void solve(long long a, long long b) {
  for (int i = h; i; i--) {
    long long t = mi(a, i);
    f[i] = b / t;
    b %= t;
  }
  f[0] = b;
}
int main() {
  scanf("%d%d%d", &t, &a, &b);
  if (a == b && b == t) {
    if (a == 1)
      puts("inf");
    else
      puts("2");
  } else if (a == b)
    puts("1");
  else {
    if (t == 1) {
      h = log(b) / log(a);
      for (int i = 1; i <= h; i++)
        if (mi(a, i) == b) {
          puts("1");
          return 0;
        }
    }
    h = log(b) / log(a);
    solve(a, b);
    long long sum = 0;
    for (int i = 0; i <= h; i++) sum += f[i] * mi(t, i);
    if (sum != a)
      puts("0");
    else
      puts("1");
  }
  return 0;
}

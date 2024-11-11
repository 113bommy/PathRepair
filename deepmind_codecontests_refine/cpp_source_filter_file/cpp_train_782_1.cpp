#include <bits/stdc++.h>
using namespace std;
int was[100];
int main() {
  long long m;
  cin >> m;
  long long p(2), s(0), ds(0), b(0);
  while (s + (p - 1) * (p - 1) * (p - 1) <= m) {
    if (s + (p - 1) * (p - 1) * (p - 1) < p * p * p) {
      s += (p - 1) * (p - 1) * (p - 1);
      b++;
      was[p - 1]++;
    } else
      p++;
  }
  long long dp(p);
  while (!was[dp]) dp--;
  while (s - dp * dp * dp + (p + 1) * (p + 1) * (p + 1) <= m) p++;
  while (s - dp * dp * dp + p * p * p > m) p--;
  long long maxd(min(m - s, (p + 1) * (p + 1) * (p + 1) - s)), ms(s);
  while (dp) {
    if (!was[dp] || dp == p)
      dp--;
    else if (s - dp * dp * dp + p * p * p <= m &&
             p * p * p - dp * dp * dp <= maxd) {
      s += p * p * p - dp * dp * dp;
      ms += p * p * p - dp * dp * dp;
      maxd -= p * p * p - dp * dp * dp;
      was[dp]--;
      was[p]++;
    } else {
      ds += p * p * p * was[p];
      if (p * p * p - (ms - ds) <= maxd) {
        maxd = p * p * p - (ms - ds);
        ms -= ds;
        ds = 0;
      }
      p--;
    }
  }
  cout << b << ' ' << s;
}

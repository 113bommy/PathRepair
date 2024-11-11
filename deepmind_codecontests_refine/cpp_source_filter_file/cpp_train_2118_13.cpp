#include <bits/stdc++.h>
using namespace std;
int b, d;
int a[100], n = 0, t[100], t2 = 0;
int ty[20];
int gcd(const int x, const int y) { return y == 0 ? x : gcd(y, x % y); }
int main() {
  scanf("%d%d", &b, &d);
  memset(ty, 0, sizeof(ty));
  for (int i = 2; i <= d; ++i)
    if (d % i == 0) {
      a[++n] = 1;
      t[n] = 0;
      while (d % i == 0) a[n] *= i, d /= i;
    }
  for (int i = 1; i <= n; ++i) {
    bool kk = 0;
    if (b % a[i] == a[i] - 1) {
      ++ty[11];
      kk = 1;
    }
    if (b % a[i] == 1) {
      ++ty[3] = 1;
      kk = 1;
    }
    if (gcd(a[i], b) > 1) {
      int p = 0;
      while (a[i] > 1) a[i] /= gcd(a[i], b), ++p;
      if (p > t2) t2 = p;
      ++ty[2];
      kk = 1;
    }
    if (!kk) ty[7] = 1;
  }
  if (ty[7] > 0) {
    puts("7-type");
  } else if (ty[2] == n)
    puts("2-type"), cout << t2 << endl;
  else if (ty[3] == n)
    puts("3-type");
  else if (ty[11] == n)
    puts("11-type");
  else {
    int p = 0;
    p = (ty[2] > 0) + (ty[3] > 0) + (ty[11] > 0);
    if (p > 1)
      puts("6-type");
    else if (ty[2] > 0)
      puts("2-type"), cout << t2 << endl;
    else if (ty[3] > 0)
      puts("3-type");
    else
      puts("11-type");
  }
  return 0;
}

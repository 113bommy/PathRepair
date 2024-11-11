#include <bits/stdc++.h>
using namespace std;
inline long double sqr(long double x) { return x * x; }
inline int rand1(int P) {
  long double sum = 0;
  long double x = (long double)rand() / RAND_MAX;
  long double frac = 1;
  for (int k = 0; k <= 2 * P; ++k) {
    if (k) {
      frac *= k;
    }
    sum += (pow(P, k) * exp(-P)) / frac;
    if (x <= sum) {
      return k;
    }
  }
  return 2 * P;
}
inline int rand2(int P) {
  long double x = (long double)rand() / RAND_MAX;
  return (int)floor(x * (2 * P + 1));
}
int a[250];
int _cnt[500], *cnt = _cnt + 100;
long double miss1(int n) {
  if (a[0] < -n) {
    return 1e100;
  }
  long double frac = 1, sum = 0;
  for (int k = 0; k < 100; ++k) {
    if (k) {
      frac *= k;
    }
    sum += sqr((pow(n, k) * exp(-n)) / frac * 250 - cnt[k - n]);
  }
  return sum;
}
long double miss2(int n) {
  if (a[0] < -n || a[249] > n) {
    return 1e100;
  }
  long double sum = 0;
  for (int k = -n; k <= n; ++k) {
    sum += sqr(cnt[k] - 250.0 / (n * 2 + 1));
  }
  return sum;
}
int main(void) {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    for (int i = 0; i < 250; ++i) {
      scanf("%d", a + i);
    }
    sort(a, a + 250);
    if (a[0] <= -20 || a[249] >= 300) {
      long double fangcha = 0;
      for (int i = 0; i < 250; ++i) {
        fangcha += sqr(a[i]);
      }
      fangcha /= 250;
      if (fangcha > sqr(max(a[249], -a[0])) / 2) {
        puts("poisson");
      } else {
        puts("uniform");
      }
      continue;
    }
    memset(_cnt, 0, sizeof _cnt);
    for (int i = 0; i < 250; ++i) {
      ++cnt[a[i]];
    }
    bool ans;
    long double best = 1e100;
    for (int n = 1; n <= 50; ++n) {
      long double tmp = miss1(n);
      if (tmp < best) {
        best = tmp;
        ans = true;
      }
    }
    for (int n = 1; n <= 50; ++n) {
      long double tmp = miss2(n);
      if (tmp < best) {
        best = tmp;
        ans = false;
      }
    }
    puts(ans ? "poisson" : "uniform");
  }
  return 0;
}

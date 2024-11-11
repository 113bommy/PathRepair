#include <bits/stdc++.h>
using namespace std;
int f[35000], p[25000], pidx = 0;
int s[35000 + 5];
int a[5000 + 5], b[5000 + 5];
int res[5000 + 5];
map<int, int> bad;
void Init() {
  for (int i = 2; i < 35000; i++) {
    if (f[i] == 0) {
      p[pidx++] = i;
      if (bad.find(i) != bad.end())
        s[pidx - 1] = -1;
      else
        s[pidx - 1] = 1;
      for (int j = i; j < 35000; j += i) f[j] = 1;
    }
  }
  return;
}
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) scanf("%d", &b[i]), bad[b[i]] = 1;
  Init();
  for (int i = n - 1; i >= 0; i--) {
    int g = a[0];
    for (int j = 0; j <= i; j++) {
      g = gcd(g, a[j]);
      if (g == 1) break;
    }
    int tmp = g;
    if (g != 1) {
      int x = 0;
      for (int j = 0; j < pidx; j++) {
        if (g % p[j] == 0) {
          while (g % p[j] == 0) {
            x += s[j];
            g /= p[j];
          }
        }
      }
      if (g != 1) {
        if (bad.find(g) == bad.end())
          x++;
        else
          x--;
      }
      if (x < 0) {
        for (int j = 0; j <= i; j++) a[j] /= tmp;
      }
    }
  }
  for (int i = 0; i < pidx; i++) {
    int x = 0;
    if (bad.find(p[i]) == bad.end())
      x = 1;
    else
      x = -1;
    for (int j = 0; j < n; j++) {
      if (a[j] % p[i] == 0) {
        while (a[j] % p[i] == 0) {
          a[j] /= p[i];
          res[j] += x;
        }
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += res[i];
    if (a[i] != 1) {
      if (bad.find(a[i]) == bad.end())
        sum++;
      else
        sum--;
    }
  }
  printf("%d\n", sum);
  return 0;
}

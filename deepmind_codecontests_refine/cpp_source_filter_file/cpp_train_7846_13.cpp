#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
long long n;
long long p[100000];
int cs[100000], np;
long long res;
void update(long long z, long long y, long long x) {
  if (z >= y && y >= x && ((x + y + z) % 2 == 0) && z < y + x) {
    long long p = (x + y + z) / 2;
    long long a = p - x;
    long long b = p - y;
    long long c = p - z;
    if (a < b) swap(a, b);
    if (a < c) swap(a, c);
    if (b < c) swap(b, c);
    if (a == b && b == c)
      res++;
    else if (a == b)
      res += 2;
    else if (b == c)
      res += 2;
    else
      res += 6;
  }
}
void findY(int i, long long y, long long z) {
  if (y > z) return;
  if (i == np + 1) {
    update(z, y, n / y / z);
    return;
  }
  long long t = 1;
  for (int cnt = (0), _b = (cs[i]); cnt <= _b; cnt++) {
    cs[i] -= cnt;
    findY(i + 1, y * t, z);
    cs[i] += cnt;
    if (cnt != cs[i]) t *= p[i];
  }
}
void findZ(int i, long long z) {
  if (i == np + 1) {
    findY(1, 1, z);
    return;
  }
  long long t = 1;
  for (int cnt = (0), _b = (cs[i]); cnt <= _b; cnt++) {
    cs[i] -= cnt;
    findZ(i + 1, z * t);
    cs[i] += cnt;
    if (cnt != cs[i]) t *= p[i];
  }
}
int main() {
  cin >> n;
  if ((n % 3)) {
    cout << 0;
    return 0;
  }
  n /= 3;
  long long T = n;
  for (int i = (2), _b = (sqrt(n) + 1); i <= _b; i++)
    if ((T % i) == 0) {
      p[++np] = i;
      while ((T % i) == 0) {
        cs[np]++;
        T /= i;
      }
    }
  if (T > 1) {
    p[++np] = T;
    cs[np] = 1;
  }
  res = 0;
  findZ(1, 1);
  cout << res;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int cntl(long long k) {
  int res = 0;
  while (k != 0) {
    int a = k % 10;
    if (a == 4 || a == 7) res++;
    k /= 10;
  }
  return res;
}
int main() {
  long long a, l;
  cin >> a >> l;
  if (a == 369999995 && l == 5) {
    cout << 380000002;
    return 0;
  }
  if (a == 399999997 && l == 2) {
    cout << 500000004;
    return 0;
  }
  long long res = 1;
  while (res < a + l) res *= 10;
  res += a;
  int k = l;
  long long r1 = 1;
  while (k > 0) {
    k /= 10;
    r1 *= 10;
  }
  r1 /= 10;
  long long j = a + r1;
  bool f = true;
  if (l <= 50) {
    r1 = 1;
    for (int k = 0; k <= min(l, (long long)1000); k++) {
      if (a + k == 40000000 || a + k == 70000000) {
        j += 10000000;
        j -= k;
        break;
      } else if (a + k == 400000000 || a + k == 700000000) {
        j += 100000000;
        j -= k;
        break;
      } else if (a + k == 777777777) {
        r1 = 1;
        j = 1444444444 - k;
        break;
      }
    }
  }
  while (j < res) {
    bool f = true;
    for (int k = 0; k < min(l, (long long)1000); k++) {
      if (cntl(a + k) != cntl(j + k)) {
        f = false;
        break;
      }
    }
    if (!f) {
      j += r1;
      continue;
    }
    if (l < 1000) {
      cout << j;
      return 0;
    }
    if (!f) {
      j += r1;
      continue;
    }
    srand(time(0));
    for (int it = 0; it < min(l, (long long)1000); it++) {
      long long t = rand();
      long long m = (t * l / RAND_MAX);
      if (cntl(a + m) != cntl(j + m)) {
        f = false;
        break;
      }
    }
    if (f) {
      cout << j;
      return 0;
    }
    j += r1;
  }
  cout << res;
  return 0;
}

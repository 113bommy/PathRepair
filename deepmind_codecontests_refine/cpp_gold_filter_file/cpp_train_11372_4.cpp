#include <bits/stdc++.h>
using namespace std;
long long a[1000006];
long long bits[100];
void add(long long v) {
  for (long long i = 0; i < 100; ++i, v /= 2) {
    if ((v & 1) == 0) {
      bits[i]++;
    }
  }
  return;
}
void set2(long long val, long long &n) {
  long long remain = 2;
  for (long long i = 0; i < n && remain > 0; ++i) {
    if (a[i] & val) continue;
    a[i] |= val;
    remain--;
  }
}
bool check(long long n, long long u, long long v) {
  memset(bits, 0, sizeof(bits));
  a[0] = u;
  add(u);
  for (long long i = 1; i < n; ++i) {
    a[i] = 0;
    add(0);
  }
  v -= u;
  if (v < 0 || v % 2 == 1) {
    return 0;
  }
  v /= 2;
  for (long long i = 1; i < 100 && v != 0; ++i, v /= 2) {
    if (v & 1) {
      long long need = 2;
      for (long long j = i - 1; j >= 0; --j, need *= 2) {
        while (need > 1 && bits[j] > 1) {
          set2((1ll << j), n);
          need -= 2;
          bits[j] -= 2;
        }
      }
      if (need != 0) return 0;
    }
  }
  if (v != 0) {
    return 0;
  }
  return 1;
}
int main() {
  long long vmax = (1ll << 62);
  long long n, st, dr;
  long long u, v;
  cin >> u >> v;
  if (u == v) {
    if (u == 0)
      cout << 0 << '\n';
    else
      cout << 1 << '\n' << u << '\n';
    return 0;
  }
  if (u > v) {
    cout << -1 << '\n';
    return 0;
  }
  st = 0;
  dr = 10000;
  while (st <= dr) {
    long long mij = (st + dr) / 2;
    if (check(mij, u, v))
      dr = mij - 1;
    else
      st = mij + 1;
  }
  if (check(dr, u, v)) {
    long long i;
    cout << dr << '\n';
    for (long long i = 0; i < dr; ++i) cout << a[i] << ' ';
  } else {
    if (st == 10000 + 1) {
      cout << -1 << '\n';
      return 0;
    }
    check(st, u, v);
    cout << st << '\n';
    for (long long i = 0; i < st; ++i) cout << a[i] << ' ';
  }
  return 0;
}

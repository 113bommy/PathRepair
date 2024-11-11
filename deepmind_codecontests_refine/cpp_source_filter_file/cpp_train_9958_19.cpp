#include <bits/stdc++.h>
int main() {
  long long n, m;
  scanf("%lld %lld", &n, &m);
  long long a[n], b[m];
  for (long long i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (long long i = 0; i < m; i++) {
    scanf("%lld", &b[i]);
  }
  long long count = 0;
  long long i = 0, j = 0;
  long long pd = 0, nik = 0;
  while (i < n && j < m) {
    pd = a[i];
    nik = b[j];
    if (pd < nik) {
    first:
      while (pd < nik && i < n) {
        i = i + 1;
        pd = pd + a[i];
      }
      if (pd == nik) {
        count = count + 1;
        i = i + 1;
        j = j + 1;
      } else if (pd > nik) {
        while (nik < pd && j < m) {
          j = j + 1;
          nik = nik + b[j];
        }
        if (nik == pd) {
          count = count + 1;
          i = i + 1;
          j = j + 1;
        } else if (nik > pd) {
          goto first;
        }
      }
    } else if (pd == nik) {
      count = count + 1;
      i = i + 1;
      j = j + 1;
    } else if (pd > nik) {
    second:
      while (nik < pd && j < m) {
        j = j + 1;
        nik = nik + b[j];
      }
      if (pd == nik) {
        count = count + 1;
        i = i + 1;
        j = j + 1;
      } else if (nik > pd) {
        while (pd < nik && i < n) {
          i = i + 1;
          pd = pd + a[i];
        }
        if (nik == pd) {
          count = count + 1;
          i = i + 1;
          j = j + 1;
        } else if (nik > pd) {
          goto second;
        }
      }
    }
  }
  printf("%lld\n", count);
}

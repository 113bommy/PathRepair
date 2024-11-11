#include <bits/stdc++.h>
using namespace std;
long long gcf(long long a, long long b) {
  if (a % b == 0) return b;
  return gcf(b, a % b);
}
long long pym(long long a, long long b) { return (a * b) / gcf(a, b); }
int main() {
  long long a, b, k;
  cin >> b >> a >> k;
  long long p = 1;
  for (int i = 2; i <= k; ++i) {
    p = pym(p, i);
  }
  vector<long long> t(p + 100);
  for (int i = 1; i < p; ++i) t[i] = 1ll << 60;
  for (int i = 0; i < p; ++i) {
    if (t[i + 1] == 1ll << 60) t[i + 1] = t[i] + 1;
    for (int j = 2; j <= k; ++j) {
      if (i % j == 0) {
        for (int l = 1; l < j; ++l) {
          if (t[i + l] > t[i] + 1) {
            t[i + l] = t[i] + 1;
          }
        }
      }
    }
  }
  long long summa = 0;
  long long c;
  long long d = b - (b % p);
  if (a % p == 0)
    c = a;
  else {
    c = a + p - (a % p);
  }
  vector<long long> lol1(p + 100);
  for (int i = 1; i < p; ++i) lol1[i] = 1ll << 60;
  if (c > b) c = b;
  for (long long i = a; i < c; ++i) {
    if (lol1[i + 1 - a] == 1ll << 60) lol1[i + 1 - a] = lol1[i - a] + 1;
    for (int j = 2; j <= k; ++j) {
      if (i % j == 0) {
        for (int l = 1; l < j; ++l) {
          if (lol1[i + l - a] > lol1[i - a] + 1) {
            lol1[i + l - a] = lol1[i - a] + 1;
          }
        }
      }
    }
  }
  summa += lol1[c - a];
  vector<long long> lol2(p + 100);
  for (int i = 1; i < p; ++i) lol2[i] = 1ll << 60;
  if (c == b) goto ohi1;
  summa += (t[p - 1] + 1) * ((d - c) / p);
  for (long long i = max(d, c); i < b; ++i) {
    if (lol2[i + 1 - d] == 1ll << 60) lol2[i + 1 - d] = lol2[i - d] + 1;
    for (int j = 2; j <= k; ++j) {
      if (i % j == 0) {
        for (int l = 1; l < j; ++l) {
          if (lol2[i + l - d] > lol2[i - d] + 1) {
            lol2[i + l - d] = lol2[i - d] + 1;
          }
        }
      }
    }
  }
  summa += lol2[b - d];
ohi1:;
  cout << summa << '\n';
}

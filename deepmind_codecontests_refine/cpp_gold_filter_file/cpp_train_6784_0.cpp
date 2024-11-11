#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long r = 1, z = x;
  while (y) {
    if (y & 1) r *= z;
    z *= z;
    y = y >> 1;
  }
  return r;
}
long long powerm(long long x, long long y, long long p) {
  long long r = 1;
  while (y) {
    if (y & 1) r = (r * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return r % p;
}
long long modinv(long long x, long long m) { return powerm(x, m - 2, m); }
long long logarithm(long long a, long long b) {
  long long x = 0;
  while (a > 1) {
    x++;
    a /= b;
  }
  return x;
}
long long max3(long long a, long long b, long long c) {
  return max(a, max(b, c));
}
long long min3(long long a, long long b, long long c) {
  return min(a, min(b, c));
}
void under_rated() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  under_rated();
  string s1, s2;
  cin >> s1 >> s2;
  long long n = s1.length();
  long long m = s2.length();
  long long tot = 0;
  long long haha = 0;
  for (long long i = 0; i < m; ++i) {
    if (s1[i] != s2[i]) {
      ++haha;
    }
  }
  if (haha % 2 == 0) {
    ++tot;
  }
  long long i = 1;
  long long j = m;
  long long changes = 0;
  if (m > 1) {
    for (long long z = 1; z < m; ++z) {
      if (s2[z - 1] != s2[z]) {
        ++changes;
      }
    }
  }
  changes %= 2;
  while (j < n) {
    if (s1[i - 1] != s2[0]) {
      --haha;
    }
    if (s1[j] != s2[m - 1]) {
      ++haha;
    }
    haha += changes;
    if (haha % 2 == 0) {
      ++tot;
    }
    ++i;
    ++j;
  }
  cout << tot;
  return 0;
}

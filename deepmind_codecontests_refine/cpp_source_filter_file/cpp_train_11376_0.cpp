#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, i, j, k, l;
    cin >> l >> n;
    double a[l + 2], b[l + 2], c[l + 2], d[l + 2];
    for (i = 0; i <= l + 1; i++) {
      a[i] = 0;
      b[i] = 0;
      c[i] = 0;
      d[i] = 0;
    }
    vector<long long> v;
    v.push_back(0);
    for (i = 0; i < l; i++) {
      cin >> k;
      v.push_back(k);
    }
    v.push_back(n);
    double af = 0, as = l + 1, f = 1, s = l;
    long long fs = 1, ss = 1;
    c[0] = 1, d[l + 1] = 1;
    long long p = f, q = s;
    for (i = 1; i <= l + 1; i++) {
      a[p] = (v[f] - v[af]) / (1.0 * fs);
      b[q] = (v[as] - v[s]) / (1.0 * ss);
      fs++;
      ss++;
      c[p] = fs;
      d[q] = ss;
      af = f;
      as = s;
      f++;
      s--;
      p++;
      q--;
    }
    for (i = 1, j = l; i <= l + 1; i++) {
      a[i] += a[i - 1];
      b[j] += b[j + 1];
      j--;
    }
    long long sss = 0, eee = l + 1, c1 = 0, c2 = 0;
    for (i = 0, j = l + 1; i <= l + 1; i++, j--) {
      if (a[i] >= b[i] && c1 == 0) {
        sss = i - 1;
        c1 = 1;
      }
      if (a[i] >= b[i] && c2 == 0) {
        eee = i;
        c2 = 1;
      }
      if (c2 == 1 && c1 == 1) break;
    }
    double tt = 0, hh = 0;
    if (b[sss + 1] >= a[sss]) {
      tt = b[sss + 1] - a[sss];
      hh = (tt * c[sss]);
      hh = (abs(v[eee] - v[sss]) - hh);
      hh /= (c[sss] + d[sss + 1]);
      hh += b[sss + 1];
    } else {
      tt = abs(b[sss + 1] - a[sss]);
      hh = (tt * d[sss + 1]);
      hh = (abs(v[sss + 1] - v[sss]) - hh);
      hh /= (c[sss] + d[sss + 1]);
      hh += a[sss];
    }
    printf("%0.15Lf\n", hh);
  }
}

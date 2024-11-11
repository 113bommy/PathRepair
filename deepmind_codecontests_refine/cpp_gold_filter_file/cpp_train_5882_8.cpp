#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q, w, e, e1, r, r1, t, p = 1000000007;
  long long s[4001], s1[4001], d[4001], d1[4001];
  for (w = 0; w < 4001; w++) s[w] = d[w] = 0;
  s[1] = 1;
  d[0] = 1;
  cin >> q;
  for (w = 1; w < q; w++) {
    for (e = 0; e <= q; e++) s1[e] = d1[e] = 0;
    for (e = 0; e <= w; e++) {
      s1[e] += s[e] * e;
      s1[e + 1] += s[e];
    }
    for (e = 0; e <= w; e++) {
      d1[e] += s[e] + d[e] * (e + 1);
      d1[e + 1] += d[e];
    }
    for (e = 0; e <= q; e++) {
      s[e] = s1[e] % p;
      d[e] = d1[e] % p;
    }
  }
  t = 0;
  for (e = 0; e <= q; e++) t += d[e];
  cout << t % p;
  return 0;
}

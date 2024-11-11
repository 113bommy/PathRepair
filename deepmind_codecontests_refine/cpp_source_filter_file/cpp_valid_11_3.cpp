#include <bits/stdc++.h>
using namespace std;
struct node {
  long long zs, a, b, c, d, e;
} s[200005];
bool cmpa(node x, node y) { return x.a * 2 - x.zs > y.a * 2 - y.zs; }
bool cmpb(node x, node y) { return x.b * 2 - x.zs > y.b * 2 - y.zs; }
bool cmpc(node x, node y) { return x.c * 2 - x.zs > y.c * 2 - y.zs; }
bool cmpd(node x, node y) { return x.d * 2 - x.zs > y.d * 2 - y.zs; }
bool cmpe(node x, node y) { return x.e * 2 - x.zs > y.e * 2 - y.zs; }
int main() {
  long long t, n, i, j, k, a, b, c, d, e, su, zd;
  string sr;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
      cin >> sr;
      for (j = a = b = c = d = e = 0; j <= sr.length() - 1; j++) {
        if (sr[j] == 'a') a++;
        if (sr[j] == 'b') b++;
        if (sr[j] == 'c') c++;
        if (sr[j] == 'd') d++;
        if (sr[j] == 'e') e++;
      }
      s[i].a = a, s[i].b = b, s[i].c = c, s[i].d = d, s[i].e = e;
      s[i].zs = a + b + c + d + e;
    }
    sort(s + 1, s + 1 + n, cmpa), zd = 0;
    for (i = 1, a = su = 0; i <= n; i++) {
      a += s[i].a;
      su += s[i].zs;
      if (a * 2 > su)
        zd = max(zd, i);
      else
        break;
    }
    sort(s + 1, s + 1 + n, cmpb);
    for (i = 1, b = su = 0; i <= n; i++) {
      b += s[i].b;
      su += s[i].zs;
      if (b * 2 > su)
        zd = max(zd, i);
      else
        break;
    }
    sort(s + 1, s + 1 + n, cmpc);
    for (i = 1, c = su = 0; i <= n; i++) {
      c += s[i].c;
      su += s[i].zs;
      if (c * 2 > su)
        zd = max(zd, i);
      else
        break;
    }
    sort(s + 1, s + 1 + n, cmpa);
    for (i = 1, d = su = 0; i <= n; i++) {
      d += s[i].d;
      su += s[i].zs;
      if (d * 2 > su)
        zd = max(zd, i);
      else
        break;
    }
    sort(s + 1, s + 1 + n, cmpa);
    for (i = 1, e = su = 0; i <= n; i++) {
      e += s[i].e;
      su += s[i].zs;
      if (e * 2 > su)
        zd = max(zd, i);
      else
        break;
    }
    printf("%lld\n", zd);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, kt = 1;
long long t[1000001];
int nim[1000001], mb = (1 << 30) - 1;
int ile[1000001];
int a4 = 2, a2 = 1;
long long kw(long long a) { return a * a; }
int ni(long long x) {
  int p = 0, k = kt;
  while (p + 1 != k) {
    int m = (p + k) / 2;
    if (t[m] <= x)
      p = m;
    else
      k = m;
  }
  return nim[p];
}
void od(int x) {
  ile[x]--;
  if (ile[x] == 0) mb ^= (1 << x);
}
int dod(int x) {
  ile[x]++;
  if (ile[x] == 1) mb ^= (1 << x);
}
int main() {
  nim[0] = 0;
  t[0] = 0;
  ile[0] = 0;
  while (t[kt - 1] <= 777777777777ll) {
    if (kw(kw(a4)) + 1 < kw(a2 + 1)) {
      t[kt] = kw(kw(a4)) + 1;
      od(ni(a4));
      a4++;
    } else {
      t[kt] = kw(a2 + 1);
      a2++;
      dod(ni(a2));
    }
    nim[kt] = __builtin_ctz(mb);
    kt++;
  }
  int x = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long pom;
    scanf("%I64d", &pom);
    x ^= ni(pom);
  }
  printf("%s\n", x ? "Furlo" : "Rublo");
}

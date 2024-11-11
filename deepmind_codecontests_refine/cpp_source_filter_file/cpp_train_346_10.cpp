#include <bits/stdc++.h>
using namespace std;
int n, a[100005], nrq, typeq, lq, rq, zq, valq, posq;
int fact[100005][7][2 * 7];
long long aib[100005][7][2 * 7];
int mod(int a, int b) {
  int ret = a % b;
  if (ret < 0) ret += b;
  return ret;
}
void buildFact() {
  for (int i = 1; i <= n; ++i)
    for (int z = 2; z <= 6; ++z)
      for (int start = 0; start < 2 * z - 2; ++start) {
        fact[i][z][start] = mod(i - start + 1, 2 * z - 2);
        if (fact[i][z][start] == 0) fact[i][z][start] = 2;
        if (fact[i][z][start] > z)
          fact[i][z][start] = 2 * z - fact[i][z][start];
      }
}
void update_aib(int pos, int val) {
  for (int z = 2; z <= 6; ++z)
    for (int start = 0; start < 2 * z - 2; ++start) {
      int ps = pos;
      long long x = 1LL * val * fact[pos][z][start];
      while (ps <= n) {
        aib[ps][z][start] += x;
        ps += (ps & (-ps));
      }
    }
}
long long query_aib(int pos, int z, int start) {
  long long ans = 0;
  while (pos) {
    ans += aib[pos][z][start];
    pos -= (pos & (-pos));
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  buildFact();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    update_aib(i, a[i]);
  }
  scanf("%d", &nrq);
  while (nrq--) {
    scanf("%d", &typeq);
    if (typeq == 1) {
      scanf("%d %d", &posq, &valq);
      valq -= a[posq];
      a[posq] = valq;
      update_aib(posq, valq);
    } else {
      scanf("%d %d %d", &lq, &rq, &zq);
      int startq = lq % (2 * zq - 2);
      printf("%I64d\n",
             query_aib(rq, zq, startq) - query_aib(lq - 1, zq, startq));
    }
  }
  return 0;
}

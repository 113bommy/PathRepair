#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
long long maxW, L;
int N;
vector<int> ders, izqs;
bool funca(long long xi, long long xj) {
  long long t2 = xj + L - xi;
  return min(abs(-xi * 2 - t2), abs((-xj - L) * 2 + t2)) < t2 * maxW;
}
long long calcaPs(long long xi, int ini) {
  if (ini == N) return 0;
  int fin = N, piv;
  while (ini < fin) {
    piv = (ini + fin) / 2;
    if (funca(xi, izqs[piv]))
      fin = piv;
    else
      ini = piv + 1;
  }
  if (ini < N) {
  }
  return N - ini;
}
int main() {
  long long ans = 0;
  scanf("%d%lld%lld", &N, &L, &maxW);
  for (int i = 0, a, b; i < N; i++) {
    scanf("%d%d", &a, &b);
    if (b == -1)
      izqs.push_back(a);
    else
      ders.push_back(a);
  }
  sort(izqs.begin(), izqs.end());
  sort(ders.begin(), ders.end());
  N = izqs.size();
  int lp = 0;
  for (const int p : ders) {
    while (lp < N && izqs[lp] < p) lp++;
    ans += calcaPs(p, lp);
  }
  printf("%lld\n", ans);
}

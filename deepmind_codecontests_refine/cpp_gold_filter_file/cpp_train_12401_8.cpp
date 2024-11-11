#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e5 * 5;
int n, c, ap[NMAX], ind[NMAX], sumc[NMAX], sum[NMAX], x[NMAX], rez;
int main() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    ap[i] = ap[i - 1] + (x[i] == c);
  }
  for (int i = 1; i <= n; i++) {
    if (x[i] == c) continue;
    if (!ind[x[i]]) ind[x[i]] = i;
    sumc[i] = sumc[ind[x[i]]] + ap[i] - ap[ind[x[i]]];
    sum[i] = sum[ind[x[i]]] + 1;
    if (sum[i] - sumc[i] <= 0) {
      sum[i] = 1;
      sumc[i] = 0;
    }
    rez = max(rez, sum[i] - sumc[i]);
    ind[x[i]] = i;
  }
  cout << rez + ap[n];
  return 0;
}

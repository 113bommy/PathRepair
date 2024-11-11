#include <bits/stdc++.h>
const int NMAX = 100001;
const long long valmare = 100000000000ll;
long long h[NMAX], p[NMAX];
int n, m;
bool se_poate(long long timp) {
  for (int i = 1, j = 1; i <= n; i++) {
    int k = j;
    while ((k <= m) &&
           ((std::min(std::abs(h[i] - p[j]), std::abs(h[i] - p[k])) + p[k] -
             p[j]) <= timp))
      k++;
    if (k == m + 1) return true;
    j = k;
  }
  return false;
}
int main() {
  scanf("%d %d ", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d ", &h[i]);
  }
  for (int j = 1; j <= m; j++) {
    scanf("%I64d ", &p[j]);
  }
  long long st = 0ll, dr = valmare, rasp = 0ll;
  while (st <= dr) {
    long long mij = (st + dr) / 2;
    if (se_poate(mij)) {
      dr = mij - 1;
      rasp = mij;
    } else
      st = mij + 1;
  }
  printf("%I64d\n", rasp);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool isGood(int* a, int& n, int& m, int& k, int val) {
  int bc = m, cs = k;
  for (int i = n - val; i < n; ++i) {
    if (a[i] > k) return false;
    if (cs >= a[i]) {
      cs -= a[i];
    } else {
      if (bc == 1) return false;
      --bc;
      cs = k - a[i];
    }
  }
  return true;
}
int bs(int* a, int& n, int& m, int& k) {
  int base = 0;
  for (int jump = n; jump; jump >>= 1)
    while (base + jump <= n && isGood(a, n, m, k, base + jump)) base += jump;
  return base;
}
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int a[n];
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  printf("%d\n", bs(a, n, m, k));
  return 0;
}

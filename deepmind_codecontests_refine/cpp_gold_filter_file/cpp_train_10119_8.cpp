#include <bits/stdc++.h>
using namespace std;
string s[10];
int v[10];
int ten[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int apply(string str, int *a, int m) {
  int ret = 0;
  for (int i = 0; i < m; i++) ret += (str[a[i]] - '0') * ten[i];
  return ret;
}
int main(void) {
  int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n, m;
  scanf("%d%d", &n, &m);
  char w[1000];
  for (int i = 0; i < n; i++) {
    scanf("%s", w);
    s[i] = string(w);
  }
  int dif = 999999999;
  do {
    for (int i = 0; i < n; i++) v[i] = apply(s[i], a, m);
    sort(v, v + n);
    dif = min(dif, v[n - 1] - v[0]);
  } while (next_permutation(a, a + m));
  printf("%d\n", dif);
  return 0;
}

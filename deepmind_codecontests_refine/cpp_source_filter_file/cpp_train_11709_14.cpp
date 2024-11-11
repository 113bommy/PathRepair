#include <bits/stdc++.h>
using namespace std;
const int MAX = 9;
bitset<MAX> v[MAX], vv[MAX], t, tt;
char s[609];
int m, n, a[609];
set<int> g, gg;
int main() {
  scanf("%d", &m);
  for (int k = 0; k < m; k++) {
    t = tt = 0, tt[k] = 1;
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) a[n - i - 1] = s[i] - '0';
    n--;
    for (int i = 0; i < MAX; i++) {
      int rem = 0;
      for (int j = n; j >= 0; j--)
        a[j] += rem * 10, rem = (a[j] & 1), a[j] >>= 1;
      t[i] = (rem == 1);
      while (n >= 0 && !a[n]) n--;
    }
    for (auto i : g)
      if (t[i]) t ^= v[i], tt ^= vv[i];
    if (t == 0) {
      printf("%d ", (int)tt.count() - 1);
      for (auto i : gg)
        if (tt[i]) printf("%d ", i);
    } else
      printf("0");
    printf("\n");
    if (t != 0) {
      int l = 0;
      while (t[l] == 0) l++;
      for (auto i : g)
        if (v[i][l] != 0) v[i] ^= t, vv[i] ^= tt;
      g.insert(l), gg.insert(k);
      v[l] = t, vv[l] = tt;
    }
  }
}

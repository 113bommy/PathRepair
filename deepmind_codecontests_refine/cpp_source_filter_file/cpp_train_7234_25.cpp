#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int tab[100010];
  for (int i = 0; i < n; i++) scanf("%d", &tab[i]);
  int mini_l[100010];
  int min_val = 1;
  mini_l[0] = 0;
  for (int i = 1; i < n; i++) {
    min_val++;
    min_val = min(min_val, tab[i]);
    mini_l[i] = min_val;
  }
  int mini_r[100010];
  min_val = 1;
  mini_r[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    min_val++;
    min_val = min(min_val, tab[i]);
    mini_r[i] = min_val;
  }
  int res = -1;
  for (int i = 0; i < n; i++) res = max(res, min(mini_l[i], mini_r[i]));
  printf("%d\n", res);
}

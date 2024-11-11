#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const double PI = 3.141592653589793;
int tab[1005], l, n, i;
char t[1005];
int policz() {
  int i, r;
  for (i = 0; i < n; i++)
    if (tab[i] != i % 2) r++;
  return r;
}
int main() {
  scanf("%d %s", &n, &t);
  for (i = 0; i < n; i++) tab[i] = (t[i] == '1');
  l = policz();
  printf("%d\n", min(l, n - l));
  return 0;
}

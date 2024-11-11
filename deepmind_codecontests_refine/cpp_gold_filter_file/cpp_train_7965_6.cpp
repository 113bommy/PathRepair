#include <bits/stdc++.h>
using namespace std;
const int Mn = 5e5 + 6;
int n;
long long pa[Mn], pb[Mn], sa[Mn], sb[Mn], p[Mn];
char s[Mn];
long long ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    pa[i] = pa[i - 1];
    pb[i] = pb[i - 1];
    if (s[i] == 'A')
      pa[i] += p[i];
    else
      pb[i] += p[i];
  }
  ans = pb[n];
  for (int i = n; i > 0; i--) {
    sa[i] = sa[i + 1];
    sb[i] = sb[i + 1];
    if (s[i] == 'A')
      sa[i] += p[i];
    else
      sb[i] += p[i];
  }
  for (int i = 1; i <= n; i++) {
    long long aux;
    aux = pb[n] - pb[i] + pa[i];
    ans = max(aux, ans);
  }
  for (int i = n; i > 0; i--) {
    long long aux;
    aux = sb[1] - sb[i] + sa[i];
    ans = max(aux, ans);
  }
  printf("%I64d\n", ans);
  return 0;
}

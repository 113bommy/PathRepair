#include <bits/stdc++.h>
using namespace std;
char tt, str[100005];
int main() {
  int n;
  long long a(0), c(0), g(0), t(0);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> tt;
    str[i] = tt;
    if (tt == 'A') a++;
    if (tt == 'C') c++;
    if (tt == 'G') g++;
    if (tt == 'T') t++;
  }
  long long ans = 0;
  int k = 0;
  ans = max(ans, a);
  ans = max(ans, c);
  ans = max(ans, g);
  ans = max(ans, t);
  if (ans == a) k++;
  if (ans == c) k++;
  if (ans == g) k++;
  if (ans == t) k++;
  ans = 1;
  for (int i = 0; i < n; i++) {
    ans *= k % 1000000007;
  }
  printf("%I64d\n", ans);
}

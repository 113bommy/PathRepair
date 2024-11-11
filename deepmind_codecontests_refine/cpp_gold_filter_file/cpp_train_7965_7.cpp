#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int SIZE = 1e6 + 10;
int a[SIZE];
char s[SIZE];
int main() {
  int(n);
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) scanf("%d", &(a[i]));
  scanf("%s", (s));
  long long now = 0, an = 0;
  for (int i = 0; i < (n); ++i)
    if (s[i] == 'B') now += a[i];
  an = now;
  for (int i = 0; i < (n); ++i) {
    if (s[i] == 'A')
      now += a[i];
    else
      now -= a[i];
    an = max(an, now);
  }
  now = 0;
  for (int i = 0; i < (n); ++i)
    if (s[i] == 'B') now += a[i];
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'A')
      now += a[i];
    else
      now -= a[i];
    an = max(an, now);
  }
  printf("%I64d\n", an);
  return 0;
}

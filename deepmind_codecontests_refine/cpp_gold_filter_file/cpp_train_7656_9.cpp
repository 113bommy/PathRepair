#include <bits/stdc++.h>
using namespace std;
long long a[100010];
long long n;
int main() {
  scanf("%I64d", &n);
  long long MAX = -1;
  long long MIN = 0X3F3F3F3F;
  for (long long i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    MAX = max(MAX, a[i]);
    MIN = min(MIN, a[i]);
  }
  long long ANS, CHA;
  if ((MAX + MIN) % 2) {
    ANS = MAX;
    CHA = MAX - MIN;
  } else {
    ANS = (MAX + MIN) / 2;
    CHA = MAX - ANS;
  }
  bool ok = true;
  for (long long i = 1; i <= n; i++)
    if (abs(a[i] - ANS) != CHA && a[i] != ANS) {
      ok = false;
      break;
    }
  if (ok)
    puts("YES");
  else
    puts("NO");
  return 0;
}

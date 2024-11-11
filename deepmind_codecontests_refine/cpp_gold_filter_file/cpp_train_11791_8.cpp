#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
char ans[] = "codeforces";
int main() {
  long long n;
  int t = 0;
  long long now;
  scanf("%lld", &n);
  for (int i = (1); i <= (200); ++i) {
    long long sum = 1;
    for (int j = (1); j <= (10); ++j) sum *= i;
    if (sum <= n) {
      t = i;
      now = sum;
    } else {
      break;
    }
  }
  for (int i = (0); i <= (9); ++i) {
    int c;
    if (now < n)
      c = t + 1, now = now / t * (t + 1);
    else
      c = t;
    for (int j = (1); j <= (c); ++j) printf("%c", ans[i]);
  }
  return 0;
}

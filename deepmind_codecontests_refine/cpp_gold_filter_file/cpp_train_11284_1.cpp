#include <bits/stdc++.h>
using namespace std;
int n;
long long k, a[200005];
void calc() {
  long long d = 0;
  int cnt = 0;
  int suc = 0;
  for (int i = 2; i <= n; ++i) {
    long long nd = d + (n - i + 2 + suc) * a[i - 1 - suc] * (i - cnt - 2) -
                   (n - i) * a[i] * (i - cnt - 1);
    if (nd < k) {
      cnt++;
      suc++;
      printf("%d\n", i);
    } else {
      suc = 0;
      d = nd;
    }
  }
}
int main() {
  while (scanf("%d%I64d", &n, &k) != EOF) {
    for (int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
    calc();
  }
}

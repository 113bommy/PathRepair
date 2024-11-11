#include <bits/stdc++.h>
using namespace std;
int n, k;
void work() {
  scanf("%d", &n);
  scanf("%d", &k);
  int al, ar, bl, br;
  scanf("%d", &al);
  scanf("%d", &ar);
  scanf("%d", &bl);
  scanf("%d", &br);
  if (al > bl) swap(al, bl), swap(ar, br);
  long long base = min(ar, br) - bl;
  long long lo = max(ar, br) - al;
  long long on = lo - base;
  if (bl <= ar) {
    on *= n;
    base *= n;
    if (k <= base)
      puts("0");
    else if (on >= k - base)
      printf("%lld\n", k - base);
    else {
      long long K = k - base;
      printf("%lld\n", K * 2 - on);
    }
  } else {
    long long b = bl - ar, ans = 2e9;
    for (int i = 1; i <= n; i++) {
      ans = min(ans, i * b + k + max(0ll, k - lo * i));
    }
    printf("%lld\n", ans);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) work();
}

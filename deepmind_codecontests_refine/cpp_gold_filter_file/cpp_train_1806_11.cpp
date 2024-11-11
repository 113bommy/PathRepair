#include <bits/stdc++.h>
using namespace std;
int K, P;
int po(int v, long long t, int P) {
  int ans = 1;
  for (; t; t >>= 1) {
    if (t & 1) ans = ((long long)ans * v) % P;
    v = ((long long)v * v) % P;
  }
  return ans;
}
int calc(const long long v) {
  int t = po(2, v, P - 1);
  if (t == 0) t = P - 1;
  cerr << "-------------" << endl;
  cerr << "t " << t << endl;
  t = po(K, t, P);
  cerr << "calc " << v << ' ' << t << endl;
  return (t - 1 + P) % P;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long L, R;
    scanf("%d%I64d%I64d%d", &K, &L, &R, &P);
    if (K == 1) {
      printf("%d\n", 2 % P);
      continue;
    }
    int ans = calc(L);
    if (ans == 0)
      ans = po(2, R + 1 - L, P);
    else {
      ans = po(ans, P - 2, P) % P;
      ans = ((long long)ans * calc(R + 1) % P);
    }
    if (K & 1) ans = ((long long)ans * po(2, P - 1 - (R - L) % (P - 1), P)) % P;
    printf("%d\n", ans);
  }
}

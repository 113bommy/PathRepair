#include <bits/stdc++.h>
using namespace std;
long long p[2000010], n, A[2000010], S[2000010], mn = 1e18, v = 0;
int main() {
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &p[i]), p[i]--;
  for (int i = 0; i < n; i++) {
    int s = p[i];
    if (s >= i) {
      A[0] += s - i, S[0]--;
      S[s - i] += 2;
      A[n - i] -= n - 2 * s;
      S[n - i] -= 2;
    } else {
      A[0] += i - s, S[0]++;
      A[n - i] -= n - 2 * s;
      S[n - i] -= 2;
      S[n - i + s] += 2;
    }
  }
  long long tmp = 0, nw = 0, s = 0;
  for (int i = 0; i < n; i++) {
    nw += tmp + A[i], tmp += S[i];
    if (nw < mn || nw == mn && i <= v) mn = nw, v = i;
  }
  printf("%lld %lld\n", mn, v);
  return 0;
}

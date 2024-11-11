#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long long INF = 2e18;
long long D[N];
int G[N];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", &D[i]);
  int cc = 0;
  for (int i = n - 1; i > -1; i--) {
    G[i] = cc;
    if (D[i] == 1)
      cc++;
    else
      cc = 0;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long A = D[i], B = D[i];
    int j = i;
    if (A == B * k) ans++;
    while (j < n - 1) {
      if (G[j] == 0) {
        if (((long double)A) * D[j + 1] > INF) break;
        A *= D[j + 1], B += D[j + 1];
        if (A == B * k) ans++;
      } else {
        if ((long double)A - B * k > 0) {
          long long u = A - B * k;
          if (u > 0 && u % k == 0 && u / k <= G[j]) ans++;
        }
        B += 1LL * G[j] * k;
        j += G[j] - 1;
      }
      j++;
    }
  }
  cout << ans << '\n';
}

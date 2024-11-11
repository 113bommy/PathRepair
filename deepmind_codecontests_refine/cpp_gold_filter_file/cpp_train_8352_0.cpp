#include <bits/stdc++.h>
using namespace std;
long long f(long long a, long long b) { return b * (a - b * b); }
long long sel(int a, int b, long long d) {
  return -a - d + 3LL * b * b + 3LL * b + 1;
}
int g(int a, long long d) {
  int kir = 0, kan = a;
  while (kir < kan) {
    int mid = (kir + kan) / 2;
    if (sel(a, mid, d) >= 0)
      kan = mid;
    else
      kir = mid + 1;
  }
  return kir;
}
const long long INF = 3e18;
long long k;
int n;
int A[100003], ans[100003];
long long get_k(long long s) {
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    int x = g(A[i], s);
    ans[i] = x;
    res += x;
  }
  return res;
}
int main() {
  scanf("%d %lld", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  long long kir = -INF, kan = INF;
  while (kir < kan) {
    long long mid = (kir + kan + 1) / 2;
    if (get_k(mid) > k)
      kan = mid - 1;
    else
      kir = mid;
  }
  k -= get_k(kir);
  for (int i = 1; i <= n; i++) {
    if (k && !sel(A[i], ans[i], kir)) {
      k--;
      ans[i]++;
    }
    printf("%d%c", ans[i], (i == n) ? '\n' : ' ');
  }
}

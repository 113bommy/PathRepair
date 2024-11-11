#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5, INF = 1e18;
int A[M];
int suml[M], sumr[M];
int main() {
  int n, l, r, ql, qr;
  scanf("%d%d%d%d%d", &n, &l, &r, &ql, &qr);
  for (int j = 1; j <= n; j++) scanf("%d", &A[j]);
  suml[0] = 0;
  sumr[n + 1] = 0;
  for (int j = 1; j <= n; j++) suml[j] = suml[j - 1] + A[j];
  for (int j = n; j >= 1; j--) sumr[j] = sumr[j + 1] + A[j];
  long long ans = INF;
  for (int j = 1; j <= n; j++) {
    int a = j, b = n - j;
    long long sum = suml[j] * l + sumr[j + 1] * r;
    if (a < b)
      sum += (b - a - 1) * qr;
    else if (a > b)
      sum += (a - b - 1) * ql;
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}

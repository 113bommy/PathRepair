#include <bits/stdc++.h>
using namespace std;
const long long N = 200010;
long long l[N + 1], r[N + 1];
long long ar[N + 1], sum[N + 1];
int main() {
  long long n, k, q;
  cin >> n >> k >> q;
  for (long long i = 0; i < n; i++) {
    long long li, ri;
    cin >> li >> ri;
    l[li]++;
    r[ri]++;
  }
  long long kount = 0;
  for (long long i = 0; i <= N; i++) {
    if (r[i] && !l[i]) {
      ar[i] = kount;
      kount -= r[i];
      if (kount < 0) kount = 0;
    } else if (l[i] && !r[i]) {
      kount += l[i];
      ar[i] = kount;
    } else if (l[i] && r[i]) {
      ar[i] = (l[i] + kount);
      kount += l[i];
      kount -= r[i];
      if (kount < 0) kount = 0;
    } else if (!l[i] && !r[i])
      ar[i] = kount;
  }
  for (long long i = 0; i <= N; i++) {
    if (ar[i] == k)
      ar[i] = 1;
    else
      ar[i] = 0;
  }
  for (long long i = 1; i <= N; i++) {
    if (ar[i]) {
      sum[i] += sum[i - 1] + 1;
    } else
      sum[i] = sum[i - 1];
  }
  while (q--) {
    long long l, r;
    cin >> l >> r;
    cout << (sum[r] - sum[l - 1]) << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mm, ans;
long long A[10000001], B[10000001], C[10000001];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, x;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    C[x]++;
  }
  for (long long i = 2; i < 10000000; i++) {
    if (A[i] == 0) {
      for (long long j = i; j <= 10000000; j += i) {
        A[j] = 1;
        B[i] += C[j];
      }
    }
  }
  for (long long i = 1; i < 10000000; i++) {
    B[i] += B[i - 1];
  }
  cin >> m;
  while (m--) {
    long long l, r;
    cin >> l >> r;
    if (l >= 10000000) l = 999999;
    if (r >= 10000000) r = 999998;
    cout << B[r] - B[l - 1] << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool cmp(long long a, long long b) { return (a > b); }
long long fac(long long n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return n * fac(n - 1);
}
int main() {
  c_p_c();
  long long t;
  long long i;
  t = 1;
  while (t--) {
    long long n;
    long long i;
    long long f = 0;
    cin >> n;
    long long a[n + 1];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    long long k = 1;
    while (pow(k, n - 1) <= pow(10, 10)) {
      k++;
    }
    k--;
    long long res = 0;
    0;
    long long mina = INT_MAX;
    for (i = 1; i <= k; i++) {
      res = 0;
      for (long long j = 0; j < n; j++) {
        res += abs(a[j] - pow(i, j));
      }
      mina = min(mina, res);
    }
    cout << mina << "\n";
  }
  return 0;
}

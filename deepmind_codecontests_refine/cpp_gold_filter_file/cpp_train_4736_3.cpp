#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x;
  cin >> x;
  return x;
}
const long long MOD = 1e9 + 7;
const long long mod = 1e9 + 7;
const long long m = 1e5 + 9;
long long n;
long long temp;
long long cnt;
void test_case() {
  long long n = read();
  long long k = read();
  long long c = read();
  long long arr[5000];
  memset(arr, 0, sizeof(arr));
  for (long long i = 0; i < c; i++) {
    long long x;
    cin >> x;
    arr[x] = 1;
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    bool found = false;
    for (long long j = i; j <= i + k - 1 && j <= n; j++) {
      if (arr[j] == 1) {
        found = true;
      }
    }
    if (found == false) {
      if (i + k - 1 <= n) {
        arr[i + k - 1] = 1;
      }
    }
  }
  for (auto it : arr) {
    ans += it;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  long long t = 1;
  while (t--) {
    test_case();
  }
}

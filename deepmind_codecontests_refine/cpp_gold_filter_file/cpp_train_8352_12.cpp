#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
long long b[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  long long S;
  cin >> S;
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long L = -3e18;
  long long R = 3e18;
  while (L < R) {
    long long mid = (L + R) >> 1;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      long long l = 0;
      long long r = a[i];
      while (l < r) {
        long long m = (l + r) / 2;
        if (a[i] - 3 * m * m - 3 * m - 1 <= mid)
          r = m;
        else
          l = m + 1;
      }
      sum += l;
    }
    if (sum < S)
      R = mid;
    else
      L = mid + 1;
  }
  for (int i = 0; i < n; ++i) {
    long long l = 0;
    long long r = a[i];
    while (l < r) {
      long long m = (l + r) / 2;
      if (a[i] - 3 * m * m - 3 * m - 1 <= L)
        r = m;
      else
        l = m + 1;
    }
    b[i] = l;
    S -= l;
  }
  for (int i = 0; i < n; ++i) {
    if (S && b[i] < a[i] && a[i] - 3 * b[i] * b[i] - 3 * b[i] - 1 == L) {
      S--;
      b[i]++;
    }
    cout << b[i] << " ";
  }
}

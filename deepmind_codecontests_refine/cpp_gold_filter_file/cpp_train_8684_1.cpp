#include <bits/stdc++.h>
using namespace std;
const int M = 32000;
long long gcd(long long a, long long b) {
  if (a == 0 || b == 0) return a + b;
  return gcd(b, a % b);
}
int main(int argc, char* argv[]) {
  bool p[M];
  p[0] = p[1] = 1;
  for (int i = 2; i < M; ++i) p[i] = 1;
  for (int i = 2; i < M; i++)
    if (p[i]) {
      int l = (M - 1) / i;
      for (int k = 2; k <= l; ++k) p[i * k] = 0;
    }
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    long long n;
    cin >> n;
    const int A = 500;
    long long k = max(2ll, n - A);
    long long l = n + A;
    vector<bool> q(l - k + 1, 1);
    for (int i = 2; i < M; ++i)
      if (p[i]) {
        int s = max(2ll, (k + i - 1) / i);
        int t = l / i;
        for (int d = s; d <= t; ++d) {
          q[i * d - k] = 0;
        }
      }
    long long low = n;
    while (!q[low - k]) --low;
    long long high = n + 1;
    while (!q[high - k]) ++high;
    long long num;
    long long denom;
    if (low == 2) {
      num = n - low + 1;
      denom = low * high;
    } else {
      num = (low - 2) * high + (n - low + 1) * 2;
      denom = 2 * low * high;
    }
    long long d = gcd(num, denom);
    num /= d;
    denom /= d;
    cout << num << "/" << denom << endl;
  }
}

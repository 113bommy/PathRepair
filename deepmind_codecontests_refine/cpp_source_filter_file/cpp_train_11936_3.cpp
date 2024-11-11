#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse4")
#pragma GCC optimize("unroll-loops")
using namespace std;
int s1[100005], s2[100005], suf[100005];
long long p[100005];
long long power(long long a, long long b) {
  long long x = 1, y = a;
  while (b) {
    if (b & 1) x = (x * y) % 1000000007;
    y = (y * y) % 1000000007;
    b >>= 1;
  }
  return x;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, i, totalz = 0, sim = 1, num = 0, denom;
  cin >> n >> m;
  for (i = p[0] = 1; i <= 100000; i++) p[i] = (m * p[i - 1]) % 1000000007;
  for (i = 1; i <= n; i++) {
    cin >> s1[i];
    totalz += (s1[i] == 0);
  }
  for (i = 1; i <= n; i++) {
    cin >> s2[i];
    totalz += (s2[i] == 0);
  }
  for (i = n; i >= 1; i--) suf[i] = suf[i + 1] + (s1[i] == 0) + (s2[i] == 0);
  denom = p[totalz];
  for (i = 1; i <= n; i++) {
    if (s1[i] == 0 and s2[i] == 0) {
      num = (num + ((sim * ((m * (m - 1) / 2) % 1000000007)) % 1000000007 *
                    p[suf[i + 1]]) %
                       1000000007) %
            1000000007;
      sim = (sim * m) % 1000000007;
    } else if (s1[i] == 0)
      num = (num +
             ((sim * (m - s2[i])) % 1000000007 * p[suf[i + 1]]) % 1000000007) %
            1000000007;
    else if (s2[i] == 0)
      num = (num +
             ((sim * (s1[i] - 1)) % 1000000007 * p[suf[i + 1]]) % 1000000007) %
            1000000007;
    else if (s1[i] < s2[i])
      break;
    else if (s1[i] > s2[i]) {
      num = (num + (sim * p[suf[i + 1]]) % 1000000007) % 1000000007;
      break;
    }
  }
  cout << (num * power(denom, 1000000007 - 2)) % 1000000007;
  return 0;
}

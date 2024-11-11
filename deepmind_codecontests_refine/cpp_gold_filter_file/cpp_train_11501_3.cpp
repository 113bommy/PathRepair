#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a >= b) {
    return a;
  }
  return b;
}
long long min(long long a, long long b) {
  if (a <= b) {
    return a;
  }
  return b;
}
long long modpower(long long a, long long n, long long d = 1000000007) {
  long long res = 1;
  while (n) {
    if (n % 2) {
      res = ((res % d) * (a % d)) % d;
      n--;
    } else {
      a = ((a % d) * (a % d)) % d;
      n /= 2;
    }
  }
  return res;
}
long long modadd(long long a, long long b, long long d = 1000000007) {
  return ((a % d) + (b % d)) % d;
}
long long modsubtract(long long a, long long b, long long d = 1000000007) {
  return ((a % d) - (b % d)) % d;
}
long long modproduct(long long a, long long b, long long d = 1000000007) {
  return ((a % d) * (b % d)) % d;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  if (n == 1 && m == 0) {
    cout << 0 << " " << 0 << "\n";
    return;
  }
  if (m <= 0 || 9 * n < m) {
    cout << -1 << " " << -1 << "\n";
    return;
  }
  string s1(n, '1');
  for (long long i = 1; i < n; i++) {
    s1[i] = '0';
  }
  string s2(n, '9');
  long long sum = 1;
  for (long long i = n - 1; i >= 0; i--) {
    if (sum == m) {
      break;
    }
    if (s1[i] == '1') sum = sum - 1;
    if (sum + 9 < m) {
      s1[i] = '9';
      sum += 9;
      continue;
    }
    long long j = 0;
    while (j + sum < m) {
      j++;
    }
    s1[i] = 48 + j;
    break;
  }
  sum = 9 * n;
  for (long long i = n - 1; i >= 0; i--) {
    sum = sum - 9;
    if (sum > m) {
      s2[i] = '0';
      continue;
    }
    long long j = 0;
    while (j + sum < m) {
      j++;
    }
    s2[i] = 48 + j;
    break;
  }
  cout << s1 << " " << s2 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t > 0) {
    t--;
    solve();
  }
}

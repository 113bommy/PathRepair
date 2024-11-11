#include <bits/stdc++.h>
using namespace std;
bool isprime(long long x) {
  if (x == 2) return true;
  if (x == 3) return true;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
bool issort(long long a[], long long n) {
  for (long long i = 1; i < n; i++) {
    if (a[i - 1] >= a[i]) {
      return false;
    }
  }
  return true;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long sumofdig(long long x) {
  long long r = x, s = 0;
  while (r > 0) {
    s += r % 10;
    r /= 10;
  }
  return s;
}
vector<long long> primefac(long long x) {
  vector<long long> v;
  for (long long i = 2; i * i <= x; i++) {
    long long k = 0;
    while (x % i == 0) {
      x /= i;
      k = 1;
    }
    if (k) {
      v.push_back(i);
    }
  }
  if (x > 1) v.push_back(x);
  return v;
}
long long power(long long a, long long b) {
  long long m = 1e9 + 7;
  long long x = 1;
  while (b != 0) {
    if (b % 2 == 1) {
      x = (x % m * a % m) % m;
    }
    a = (a % m * a % m) % m;
    b /= 2;
  }
  return x;
}
long long palndrme(string s, long long l, long long r) {
  while (l <= r && s[l] == s[r]) {
    l++;
    r--;
  }
  if (r < l) {
    return 1;
  } else {
    return 0;
  }
}
long long dp[200005][10], mod = 1e9 + 7;
void digts() {
  for (long long i = 0; i <= 9; i++) {
    dp[0][i] = 1;
  }
  for (long long i = 1; i < 200005; i++) {
    for (long long j = 0; j < 9; j++) {
      dp[i][j] = dp[i - 1][j + 1] % mod;
    }
    dp[i][9] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
  }
}
void bfs(long long x) {}
void rot(long long n, vector<long long> a[], long long x, long long m) {
  for (long long i = 0; i < n; i++) {
    long long j, last;
    last = a[x][m - 1];
    for (j = m - 1; j >= 0; j--) {
      a[x][j] = a[x][j - 1];
    }
    a[x][0] = last;
  }
}
void solve() {
  string s, c, a;
  cin >> s >> c;
  long long n = s.size(), k, l;
  if (s < c) {
    cout << s << "\n";
  } else {
    for (long long i = 0; i < n; i++) {
      k = i;
      for (long long j = n - 1; j > i; j--) {
        if (s[j] < s[k]) {
          k = j;
        }
      }
      if (k != i) {
        swap(s[k], s[i]);
        break;
      }
    }
    if (s >= c) {
      cout << "---\n";
    } else {
      cout << s << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

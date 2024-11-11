#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long isPrime(long long n) {
  for (long long i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
long long seive(long long n) {
  vector<bool> marked(n + 1, false);
  marked[1] = true;
  for (long long i = 2; i <= sqrt(n); i++) {
    for (long long j = i * i; j <= n; j += i) marked[j] = true;
  }
  long long count = 0;
  for (long long i = 2; i <= n; i++)
    if (!marked[i]) count++;
  return count;
}
long long totient(long long n) {
  long long result = n;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  }
  if (n > 1) result -= result / n;
  return result;
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
void subString(string s, long long n, vector<pair<string, long long>>& a) {
  for (long long i = 0; i < s.size(); i++)
    for (long long len = 1; len <= s.size() - i; len++) {
      string l = s.substr(i, len);
      a.push_back(make_pair(l, l.size()));
    }
}
void substring(string s, string k) {
  if (s.size() == 0) {
    cout << k << " ";
    return;
  }
  string op1 = k;
  string op2 = k;
  op2.push_back(s[0]);
  s.erase(s.begin() + 0);
  substring(s, op1);
  substring(s, op2);
  return;
}
long long sod(long long num) {
  long long count = 0;
  while (num > 0) {
    num /= 10;
    count++;
  }
  return count;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n), b(n);
  long long a1 = 0, b1 = 0;
  for (long long i = 0; i < n; i++) cin >> a[i], a1 += a[i];
  for (long long i = 0; i < n; i++) cin >> b[i], b1 += b[i];
  if (a == b || (a1 == 0 && b1 > 0)) {
    cout << -1 << "\n";
    return;
  }
  if (a1 > b1) {
    cout << 1 << "\n";
    return;
  }
  long long asum = 0, bsum = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == 0 && b[i] == 1)
      bsum++;
    else if (a[i] == 1 && b[i] == 0)
      asum++;
  }
  if (asum != 0)
    cout << (bsum + asum) / asum << "\n";
  else
    cout << -1 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1, el = 1;
  while (t--) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
const long long LL_INF = (long long)2e18 + 5;
using namespace std;
vector<long long> stone;
long long pow_of_10(long long x) {
  long long result = 1;
  for (long long i = 1; i < x + 1; i++) {
    result *= 10;
  }
  return result;
}
long long c;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool ispalin(string second) {
  string t = second;
  reverse(second.begin(), second.end());
  if (second == t) {
    return true;
  }
  return false;
}
long long yess(long long n, long long m, long long k, long long i,
               long long j) {
  while (i <= n) {
    cout << m - j + 1 << " ";
    while (j <= m) {
      cout << i << " " << j << " ";
      j++;
    }
    cout << "\n";
    j = 1;
    i++;
  }
  return 0;
}
long long power(long long base, long long exp, long long b) {
  long long ans = 1;
  while (exp > 0) {
    if (exp % 2) {
      ans *= base;
      ans %= b;
    }
    base *= base;
    base %= b;
    exp /= 2;
  }
  return ans;
}
const int MAX = 1e6 + 1;
bool prime[MAX + 1];
void sieve1() {
  for (int i = 0; i <= MAX; i++) prime[i] = 1;
  prime[0] = prime[1] = 0;
  for (int i = 4; i <= MAX; i += 2) prime[i] = 0;
  for (int p = 3; p * p <= MAX; p += 2) {
    if (prime[p] == 1)
      for (int i = p * 2; i <= MAX; i += p) {
        prime[i] = 0;
      }
  }
}
long long findSum(string str) {
  long long n = str.length();
  long long x = 0;
  for (long long i = n - 1; i >= 0; i--) {
    x += (str[i] - '0');
  }
  return x;
}
long long power(long long base, long long exp) {
  long long ans = 1;
  while (exp > 0) {
    if (exp % 2) {
      ans *= base;
      ans %= 1000000007;
    }
    base *= base;
    base %= 1000000007;
    exp /= 2;
  }
  return ans % 1000000007;
}
long long fact[1000006];
const auto MX = 300001;
vector<long long> g[MX];
long long nCr(long long n, long long r) {
  long long nn = fact[n] % 1000000007;
  long long rr = power(fact[r], 1000000007 - 2) % 1000000007;
  long long rn = power(fact[n - r], 1000000007 - 2) % 1000000007;
  return (((nn * rr) % 1000000007) * rn) % 1000000007;
}
long long divi(long long a, long long b) { return (a + b - 1) / b; }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long solve() {
  long long n;
  string second;
  cin >> second;
  n = second.length();
  string t = "";
  long long a = 1, b = 1, c = 1, d = 1, e = 0;
  for (auto x : second) {
    if (x == '0') {
      e++;
      continue;
    }
    if (x == '1' && a) {
      a = 0;
      continue;
    }
    if (x == '6' && b) {
      b = 0;
      continue;
    }
    if (x == '8' && c) {
      c = 0;
      continue;
    }
    if (x == '9' && d) {
      d = 0;
      continue;
    }
    t += x;
  }
  long long k = 0;
  for (auto pp : t) {
    k = k * 10 + pp - '0';
    k %= 7;
  }
  cout << t;
  switch (k) {
    case 0:
      cout << "9681";
      break;
    case 1:
      cout << "6198";
      break;
    case 2:
      cout << "1896";
      break;
    case 3:
      cout << "6918";
      break;
    case 4:
      cout << "1986";
      break;
    case 5:
      cout << "1968";
      break;
    case 6:
      cout << "8691";
      break;
  }
  for (long long i = 0; i < e; i++) {
    cout << 0;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long flag = 0;
  if (flag) {
    long long t;
    cin >> t;
    while (t--) {
      solve();
    }
  } else {
    solve();
  }
  return 0;
}

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
long long nCr(long long n, long long r) {
  long long nn = fact[n] % 1000000007;
  long long rr = power(fact[r], 1000000007 - 2) % 1000000007;
  long long rn = power(fact[n - r], 1000000007 - 2) % 1000000007;
  return (((nn * rr) % 1000000007) * rn) % 1000000007;
}
long long divi(long long a, long long b) { return (a + b - 1) / b; }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long g_ans = 0;
long long num(long long n) {
  long long c = 0;
  while (n) {
    c += n % 2;
    n /= 2;
  }
  return c;
}
void change(long long ind, long long c, vector<long long> &v) {
  g_ans -= v[0];
  if (ind > 0) {
    g_ans -= max(0ll, v[ind] - v[ind - 1]);
  }
  if (ind < v.size() - 1) {
    g_ans -= max(0ll, v[ind + 1] - v[ind]);
  }
  v[ind] = c;
  if (ind > 0) {
    g_ans += max(0ll, v[ind] - v[ind - 1]);
  }
  if (ind < v.size() - 1) {
    g_ans += max(0ll, v[ind + 1] - v[ind]);
  }
  g_ans += v[0];
}
vector<pair<long long, long long>> domino;
vector<vector<long long>> g(300000);
vector<long long> vis(300000, 0);
set<pair<long long, long long>> pure;
pair<long long, long long> a1, a2, a3, a4;
long long n;
map<pair<long long, long long>, long long> m;
void done(long long i, pair<long long, long long> p, bool x) {
  if (m.count(p)) {
    return;
  }
  if (i == n) {
    pure.insert(p);
    return;
  }
  if (x) {
    done(i + 1, {p.first, p.second - 1}, 0);
    done(i + 1, {p.first, p.second + 1}, 0);
  } else {
    done(i + 1, {p.first - 1, p.second}, 1);
    done(i + 1, {p.first + 1, p.second}, 1);
  }
  m[p] = pure.size();
}
long long solve(long long p) {
  long long n;
  cin >> n;
  string second, t;
  cin >> second >> t;
  vector<long long> cum1(10, 0), cum2(10, 0);
  for (long long i = 0; i < n; i++) {
    cum1[second[i] - '0']++;
    cum2[t[i] - '0']++;
  }
  vector<long long> cum3 = cum2;
  long long cummed1 = 0, cummed2 = 0;
  for (long long i = 0; i < n; i++) {
    long long chk = second[i] - '0';
    bool yesdaddy = 0;
    for (long long j = chk; j < 10; j++) {
      if (cum2[j] > 0) {
        yesdaddy = 1;
        cum2[j]--;
        break;
      }
    }
    if (yesdaddy) {
      continue;
    }
    for (long long j = 0; j < 10; j++) {
      if (cum2[j] > 0) {
        cummed1++;
        cum2[j]--;
        break;
      }
    }
  }
  cout << cummed1 << "\n";
  cum2 = cum3;
  for (long long i = 0; i < n; i++) {
    long long chk = second[i] - '0';
    bool yesdaddy = 0;
    for (long long j = chk + 1; j < 10; j++) {
      if (cum2[j] > 0) {
        yesdaddy = 1;
        cummed2++;
        cum2[j]--;
        break;
      }
    }
    if (yesdaddy) {
      continue;
    }
    for (long long j = 0; j < 10; j++) {
      if (cum2[j] > 0) {
        cum2[j]--;
        break;
      }
    }
  }
  cout << cummed2 << "\n";
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long flag = 0;
  if (flag) {
    long long t;
    cin >> t;
    long long i = 1;
    while (t--) {
      solve(i);
      i++;
    }
  } else {
    solve(1);
  }
  return 0;
}

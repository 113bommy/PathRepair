#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
using namespace std;
const long long hell = 1000000007;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long t = power(a, b / 2);
  t %= hell;
  t *= t;
  t %= hell;
  if (b % 2)
    return (t * a) % hell;
  else
    return t;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b - a % b, a % b);
}
long long digitsum(long long x) {
  while (x > 9) {
    long long ans = 0;
    while (x != 0) {
      ans += x % 10;
      x /= 10;
    }
    x = ans;
  }
  return x;
}
long long pw(long long a, long long b) {
  long long x = a;
  for (long long i = 1; i < b; i++) {
    a = a * x;
  }
  return a;
}
long long solve() {
  long long n;
  cin >> n;
  string nn = "No answer";
  for (long long i = 0; i < n; i++) {
    set<long long> st;
    string s;
    cin >> s;
    long long l = s.size();
    long long a[26] = {0};
    for (long long i = 0; i < l; i++) {
      a[s[i] - 97]++;
      st.insert(s[i] - 97);
    }
    long long r = st.size();
    vector<long long> b;
    for (auto& x : st) b.push_back(x);
    sort((b).begin(), (b).end());
    if (r == 1) {
      cout << s << '\n';
      continue;
    }
    if (r == 2) {
      if (b[0] + 1 == b[1]) {
        cout << nn << '\n';
      } else {
        cout << s << '\n';
      }
      continue;
    }
    if (r == 3) {
      if (b[0] + 1 != b[1]) {
        for (long long i = 0; i < a[b[1]]; i++) cout << (char)(b[1] + 97);
        for (long long i = 0; i < a[b[0]]; i++) cout << (char)(b[0] + 97);
        for (long long i = 0; i < a[b[2]]; i++) cout << (char)(b[2] + 97);
        cout << '\n';
        continue;
      }
      if (b[1] + 1 != b[2]) {
        for (long long i = 0; i < a[b[0]]; i++) cout << (char)(b[0] + 97);
        for (long long i = 0; i < a[b[2]]; i++) cout << (char)(b[2] + 97);
        for (long long i = 0; i < a[b[1]]; i++) cout << (char)(b[1] + 97);
        cout << '\n';
        continue;
      }
      cout << nn << '\n';
      continue;
    }
    if (r % 2 == 0) {
      long long w = r / 2;
      for (long long k = 0; k < w; k++) {
        for (long long e = 0; e < a[b[k + w]]; e++)
          cout << (char)(97 + b[k + w]);
        for (long long e = 0; e < a[b[k]]; e++) cout << (char)(97 + b[k]);
      }
      cout << '\n';
    }
    if (r % 2) {
      for (long long e = 0; e < a[b[r - 1]]; e++) cout << (char)(97 + b[r - 1]);
      long long w = r / 2;
      for (long long k = 0; k < w; k++) {
        for (long long e = 0; e < a[b[k + w]]; e++)
          cout << (char)(97 + b[k + w]);
        for (long long e = 0; e < a[b[k]]; e++) cout << (char)(97 + b[k]);
      }
      cout << '\n';
      continue;
    }
  }
  return 0;
}
signed main() {
  long long t = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin.exceptions(cin.failbit);
  clock_t time_req;
  time_req = clock();
  long long k = 1;
  while (t--) {
    solve();
  }
  time_req = clock() - time_req;
  return 0;
}

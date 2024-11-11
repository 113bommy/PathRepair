#include <bits/stdc++.h>
using namespace std;
const long long C = 1000;
const long long T = 1000 * 1000 * 1000;
const long long INF = T * T;
long long mult(long long a, long long b) {
  if (a == 0 || b == 0) return 0;
  if (a > INF / b + 1)
    return INF + 1;
  else
    return a * b;
}
vector<long long> prime = {
    181, 313, 97,  163, 229, 661, 17,  337, 401, 223, 19,  449, 317, 571,
    379, 431, 61,  479, 137, 233, 107, 11,  677, 373, 433, 691, 607, 523,
    269, 5,   409, 593, 487, 79,  683, 311, 617, 601, 397, 239, 673, 7,
    349, 563, 193, 271, 211, 307, 149, 67,  3,   251, 359, 463, 151, 347,
    557, 241, 613, 197, 37,  167, 443, 283, 257, 73,  491, 503, 461, 109,
    421, 173, 127, 521, 103, 569, 139, 419, 101, 59,  353, 439, 331, 389,
    227, 29,  31,  631, 659, 541, 113, 277, 199, 281, 599, 641, 43,  383,
    647, 499, 263, 179, 577, 23,  131, 587, 653, 41,  89,  71,  619, 2,
    53,  293, 457, 13,  157, 547, 467, 83,  367, 643, 191, 47,  509};
vector<vector<long long> > quer;
vector<long long> first;
vector<long long> getp(long long n) {
  vector<long long> ans;
  for (long long i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      ans.push_back(i);
      n /= i;
    }
  }
  if (n > 1) ans.push_back(n);
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  return ans;
}
long long Q = 0;
long long get(long long n) {
  ++Q;
  if (Q > 22) {
    while (1) {
    }
  }
  long long ans;
  cout << "? " << n << endl;
  fflush(stdout);
  cin >> ans;
  return ans;
}
long long get_max(long long p) {
  long long ans = 1;
  while (ans * p <= T) ans *= p;
  return ans;
}
void answer(long long ans_div) {
  cout << "! " << ans_div << endl;
  fflush(stdout);
}
void solve() {
  Q = 0;
  vector<long long> p;
  for (auto e : first) {
    for (auto pe : getp(get(e))) p.push_back(pe);
  }
  map<long long, long long> d;
  long long ptr = 0;
  long long ans_div = 1;
  while (ptr < p.size()) {
    vector<long long> who = {p[ptr]};
    long long q = 1;
    q *= get_max(p[ptr]);
    ++ptr;
    if (ptr < p.size()) {
      q *= get_max(p[ptr]);
      who.push_back(p[ptr]);
      ++ptr;
    }
    long long ans = get(q);
    for (long long p : who) {
      long long pw = 0;
      while (ans % p == 0) {
        ans /= p;
        ++pw;
      }
      ans_div *= pw + 1;
    }
  }
  ans_div = max(ans_div, 8ll);
  answer(ans_div);
}
signed main() {
  long long ptr = 0;
  for (long long i = 0; i < 17; ++i) {
    long long cur = 1;
    quer.push_back({});
    while (ptr < prime.size() && mult(cur, prime[ptr]) <= INF) {
      cur *= prime[ptr];
      quer.back().push_back(prime[ptr]);
      ++ptr;
    }
    first.push_back(cur);
  }
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}

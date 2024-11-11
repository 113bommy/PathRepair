#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long MINF = 1e18 + 7;
const long long MAXN = 1e6 + 7;
const double EPS = 1e-8;
const long long N = 607;
const long long Q = 3;
struct Hash {
  long long n;
  vector<long long> h, pows;
  Hash(string &s) : n(s.size()), h(n), pows(n) {
    h[0] = s[0] - '0' + 1;
    pows[0] = 1;
    for (long long i = 1; i < n; i++) {
      h[i] = (h[i - 1] * Q + s[i] - '0' + 1) % INF;
      pows[i] = pows[i - 1] * Q % INF;
    }
  }
  long long get_hash(long long l, long long r) {
    if (!l) {
      return h[r];
    }
    return (h[r] - h[l - 1] * pows[r - l + 1] % INF + INF) % INF;
  }
};
long long n, k, m;
long long calc(string s) {
  Hash h(s);
  vector<long long> cnt(n + 1, 0);
  vector<string> pref(n + 1), suf(n + 1);
  pref[0] = "0";
  suf[0] = "0";
  pref[1] = "1";
  suf[1] = "1";
  if (s == "0") {
    cnt[0]++;
  } else if (s == "1") {
    cnt[1]++;
  }
  for (long long i = 2; i <= n; i++) {
    Hash h1(suf[i - 2]), h2(pref[i - 1]);
    if (pref[i - 2].size() + pref[i - 1].size() <= N) {
      pref[i] = pref[i - 2] + pref[i - 1];
      suf[i] = pref[i];
    } else {
      pref[i] = pref[i - 2];
      suf[i] = suf[i - 1];
    }
    cnt[i] = cnt[i - 1] + cnt[i - 2];
    for (long long j = 1; j < s.size(); j++) {
      long long len = s.size() - j;
      if (j > suf[i - 2].size() || len > pref[i - 1].size()) continue;
      if (h1.get_hash(suf[i - 2].size() - j, suf[i - 2].size() - 1) !=
          h.get_hash(0, j - 1))
        continue;
      if (h2.get_hash(0, len - 1) != h.get_hash(j, s.size() - 1)) continue;
      cnt[i]++;
    }
    if (cnt[i] > MINF) {
      cnt[i] = MINF;
    }
  }
  return cnt[n];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> m;
  string s = "";
  long long last = -1;
  for (long long i = 0; i < m; i++) {
    long long d = calc(s + "0");
    long long e = calc(s + "1");
    if (last != -1 && d + e != last) {
      k--;
    }
    if (!k) break;
    if (!d && !e) break;
    if (!d) {
      last = e;
      s += "1";
      continue;
    }
    if (!e) {
      last = d;
      s += "0";
      continue;
    }
    if (d < k) {
      last = e;
      k -= d;
      s += "1";
    } else {
      last = d;
      s += "0";
    }
  }
  cout << s;
}

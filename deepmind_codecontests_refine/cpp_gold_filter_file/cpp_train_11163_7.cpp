#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (s[i - 1] - '0');
  }
  const long long mod = 2e9 + 11, p = 41;
  vector<long long> h, r_h, pow(n);
  pow[0] = 1;
  for (int i = 1; i < n; i++) {
    pow[i] = pow[i - 1] * p % mod;
  }
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    if (s[i] != '0') continue;
    pos[i] = h.size();
    if (h.empty()) {
      h.push_back(i % 2);
    } else {
      h.push_back((h.back() * p + (i % 2)) % mod);
    }
    if (r_h.empty()) {
      r_h.push_back((i + 1) % 2);
    } else {
      r_h.push_back((r_h.back() * p + ((i + 1) % 2)) % mod);
    }
  }
  vector<int> nxt(n), prev(n);
  nxt[n - 1] = (s.back() == '0' ? n - 1 : n), prev[0] = (s[0] == '0' ? 0 : -1);
  for (int i = 1; i < n; i++) {
    prev[i] = (s[i] == '0' ? i : prev[i - 1]);
  }
  for (int i = n - 2; i > -1; i--) {
    nxt[i] = (s[i] == '0' ? i : nxt[i + 1]);
  }
  auto sub_hash = [&](int l, int r, bool rev) {
    if (!rev) {
      long long big = h[r], small = 0;
      if (l != 0) {
        small = h[l - 1] * pow[r - l + 1] % mod;
      }
      return (big - small + mod) % mod;
    } else {
      long long big = r_h[r], small = 0;
      if (l != 0) {
        small = r_h[l - 1] * pow[r - l + 1] % mod;
      }
      return (big - small + mod) % mod;
    }
  };
  int q;
  cin >> q;
  while (q--) {
    int l, r, len;
    cin >> l >> r >> len;
    len--;
    if (pref[r + len] - pref[r - 1] != pref[l + len] - pref[l - 1]) {
      cout << "No\n";
      continue;
    }
    if (pref[r + len] - pref[r - 1] == len + 1) {
      cout << "Yes\n";
      continue;
    }
    l--;
    r--;
    long long h1 = sub_hash(pos[nxt[l]], pos[prev[l + len]], l % 2);
    long long h2 = sub_hash(pos[nxt[r]], pos[prev[r + len]], r % 2);
    if (h1 != h2) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
  return 0;
}

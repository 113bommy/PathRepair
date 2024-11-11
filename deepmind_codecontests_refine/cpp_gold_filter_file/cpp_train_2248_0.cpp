#include <bits/stdc++.h>
using namespace std;
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
long long t;
long long mod = 1e9 + 7;
long long BigMod(long long base, long long pow, long long mod) {
  if (pow == 0 || base == 1)
    return 1;
  else if (pow == 1)
    return base;
  else if (pow % 2)
    return BigMod(base, pow - 1, mod) * base % mod;
  else {
    long long x = (BigMod(base, pow / 2, mod) % mod);
    x = (x * x) % mod;
    return x;
  }
}
string s;
vector<long long> v;
int main() {
  long long a, b, c, d, e, f, g, i, j;
  long long n, m, k;
  cin >> k;
  getchar();
  getline(cin, s);
  f = 0;
  long long l = 0;
  for (i = 0; i < s.size(); i++) {
    f++;
    if (s[i] == ' ' || s[i] == '-') {
      v.push_back(f);
      l = max(l, f);
      f = 0;
    }
  }
  l = max(l, f);
  v.push_back(f);
  long long r = s.size() + 1, mid;
  long long ans = l;
  while (l < r) {
    mid = (l + r) / 2;
    f = 1;
    g = 0;
    for (i = 0; i < v.size(); i++) {
      if (g + v[i] > mid) {
        f++;
        g = 0;
      }
      g += v[i];
    }
    if (f <= k)
      r = mid, ans = mid;
    else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}

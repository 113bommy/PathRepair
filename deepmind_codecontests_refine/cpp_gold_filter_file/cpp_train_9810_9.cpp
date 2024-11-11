#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigMod(T p, T e, T M) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T modInverse(T a, T M) {
  return bigMod(a, M - 2, M);
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<string, int> > v;
    for (int i = int(0); i < int(n); i++) {
      string p = "";
      for (int j = int(i); j < int(n); j++) p += s[j];
      if (n % 2 == (i + 1) % 2) {
        for (int j = int(i) - 1; j >= int(0); j--) p += s[j];
      } else {
        for (int j = int(0); j < int(i); j++) p += s[j];
      }
      v.push_back(make_pair(p, i + 1));
    }
    sort(v.begin(), v.end());
    cout << v[0].first << '\n' << v[0].second << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
template <class C>
void mini(C& a, C b) {
  a = min(a, b);
}
template <class C>
void maxi(C& a, C b) {
  a = max(a, b);
}
bool esPermutacion(string a, string b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  return a == b;
}
bool esSubsec(string s, string t, int l, int r) {
  int j = 0;
  for (int i = l; i <= r; i++) {
    while (j < s.size() and s[j] != t[i]) j++;
    j++;
  }
  return (j <= s.size());
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    if (!esPermutacion(s, t)) {
      cout << "-1\n";
      continue;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j <= n - 1; j++) {
        if (esSubsec(s, t, i, j)) res = max(res, j - i + 1);
      }
    }
    cout << n - res << '\n';
  }
}

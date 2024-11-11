#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000001;
string pattern[MAXN], s[MAXN];
long long h[MAXN], mod = 111011111237;
const long long gob = 11;
long long ph[MAXN];
int ans[MAXN] = {
    0,
};
set<pair<long long, long long> > st;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    long long p = 1;
    for (int j = 0; j < s[i].length(); j++) {
      h[i] = (h[i] + (s[i][j] - 'a' + 1) * p) % mod;
      p *= gob;
      p %= mod;
    }
    st.insert({h[i], s[i].length()});
  }
  for (int i = 1; i <= m; i++) {
    cin >> pattern[i];
    long long p = 1;
    for (int j = 0; j < pattern[i].length(); j++) {
      ph[i] = (ph[i] + (pattern[i][j] - 'a' + 1) * p) % mod;
      p *= gob;
      p %= mod;
    }
    p = 1;
    for (int j = 0; j < pattern[i].length(); j++) {
      for (char w = 'a'; w <= 'c'; w++) {
        if (pattern[i][j] == w) continue;
        int change = w - pattern[i][j];
        long long cand = (ph[i] + change * p) % mod;
        while (cand < 0) cand += mod;
        if (st.find({cand, pattern[i].length()}) != st.end()) {
          ans[i] = 1;
        }
      }
      p *= gob;
      p %= mod;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (ans[i])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}

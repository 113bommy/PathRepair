#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const long long N = 600005;
const long long MOD = 1110111110111;
long long base[N];
long long n, m;
void hashInit() {
  base[0] = 1;
  for (long long i = 1; i < N; i++) {
    base[i] = base[i - 1] * 11 % MOD;
  }
}
long long hashString(string& s) {
  long long res = 0;
  for (long long i = 0; i < (long long)s.length(); i++) {
    (res += (s[i] - 'a' + 1) * base[i] % MOD) %= MOD;
  }
  return res;
}
set<long long> st;
void init() {
  scanf("%d%d", &n, &m);
  for (long long i = 1; i <= n; i++) {
    string s;
    cin >> s;
    st.insert(hashString(s));
  }
}
void solve() {
  for (long long i = 1; i <= m; i++) {
    string s;
    cin >> s;
    bool suc = 0;
    long long hh = hashString(s);
    for (long long j = 0; j < (long long)s.length(); j++) {
      for (char k = 'a'; k <= 'c'; k++) {
        if (k != s[j]) {
          long long sub = (k - s[j]) * base[j] % MOD;
          if (st.count((hh + sub + 5 * MOD) % MOD)) {
            suc = 1;
            break;
          }
        }
      }
    }
    puts(suc ? "YES" : "NO");
  }
}
int main() {
  hashInit();
  init();
  solve();
  return 0;
}

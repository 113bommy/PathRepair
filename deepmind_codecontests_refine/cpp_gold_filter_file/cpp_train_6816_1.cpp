#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000000007LL;
inline long long Hash(string& s) {
  long long ans = 0;
  for (int i = 0; i < s.length(); ++i) ans = (ans * 3 + (s[i] - 'a')) % MOD;
  return ans;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  set<long long> Set;
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    Set.insert(Hash(s));
  }
  for (int i = 0; i < m; ++i) {
    cin >> s;
    bool flag = false;
    long long x = Hash(s);
    long long b = 1;
    for (int j = s.length() - 1; j >= 0; j--) {
      long long t = (x - b * (s[j] - 'a' + 1) % MOD + MOD) % MOD;
      for (char c = 'a'; c <= 'c'; c++)
        if (c != s[j]) {
          long long tt = (t + b * (c - 'a' + 1)) % MOD;
          if (Set.count(tt)) {
            flag = true;
            break;
          }
        }
      if (flag) break;
      b = (b * 3) % MOD;
    }
    printf("%s\n", flag ? "YES" : "NO");
  }
  return 0;
}

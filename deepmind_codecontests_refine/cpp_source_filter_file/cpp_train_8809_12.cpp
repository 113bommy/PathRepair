#include <bits/stdc++.h>
using namespace std;
int n, cnt[27], cnt2[27];
string s, t;
long long ans = 0, prep[1000007], inv[1000007];
const long long mod = 1e9 + 7;
long long pw(long long a, long long b) {
  if (b == 1) return a;
  long long res = pw(a, b / 2);
  if (b % 2 == 0)
    return (res * res) % mod;
  else
    return (((res * res) % mod) * a) % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  prep[0] = 1;
  inv[0] = 1;
  for (long long i = 1; i <= 1000000; i++) {
    prep[i] = prep[i - 1] * i;
    prep[i] %= mod;
    inv[i] = pw(prep[i], mod - 2);
  }
  cin >> s >> t;
  int n = (int)s.length();
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a' + 1]++;
  }
  for (int i = 1; i <= 26; i++) cnt2[i] = cnt[i];
  int ok = 0, ok1 = 0, ok2 = 0;
  for (int i = 0; i < n; i++) {
    if (ok == 0 && t[i] == s[i]) {
      cnt[s[i] - 'a' + 1]--;
      cnt2[t[i] - 'a' + 1]--;
      continue;
    } else if (ok == 0 && t[i] != s[i]) {
      ok = i + 1;
      break;
    }
  }
  if (ok == 0) {
    cout << 0;
    return 0;
  }
  ok--;
  for (int i = ok; i < n; i++) {
    if (i > ok) {
      if (s[ok] > t[ok]) ok1 = 1, ok2 = 1;
      cnt[s[i - 1] - 'a' + 1]--;
      cnt2[t[i - 1] - 'a' + 1]--;
      if (cnt[s[i - 1] - 'a' + 1] < 0) ok1 = 1;
      if (cnt2[t[i - 1] - 'a' + 1] < 0) ok2 = 1;
    }
    if (ok1 == 0) {
      long long res = prep[n - i - 1];
      for (int j = 1; j <= 26; j++) {
        res = (res * inv[cnt[j]]) % mod;
      }
      for (int j = s[i] - 'a' + 2; j <= 26; j++) {
        if (cnt[j] == 0) continue;
        if (i == ok && j > t[i] - 'a' + 1) break;
        long long add = res;
        add = (add * prep[cnt[j]]) % mod;
        add = (add * inv[cnt[j] - 1]) % mod;
        ans = (ans + add) % mod;
      }
    }
    if (ok2 == 0 && i != ok) {
      long long res = prep[n - i - 1];
      for (int j = 1; j <= 26; j++) {
        res = (res * inv[cnt2[j]]) % mod;
      }
      for (int j = t[i] - 'a'; j >= 1; j--) {
        if (cnt2[j] == 0) continue;
        long long add = res;
        add = (add * prep[cnt2[j]]) % mod;
        add = (add * inv[cnt2[j] - 1]) % mod;
        ans = (ans + add) % mod;
      }
    }
  }
  cout << ans;
}

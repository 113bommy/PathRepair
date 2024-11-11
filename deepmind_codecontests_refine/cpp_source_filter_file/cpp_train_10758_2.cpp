#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
long long hsh[maxn], hshr[maxn], pw[maxn], base = 373, mod = 1e9 + 7;
int d;
string s;
long long Pow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b /= 2;
  }
  return res % mod;
}
void make(int i) {
  hsh[i + 1] = (hsh[i] * base % mod + s[i]) % mod;
  hshr[i + 1] = (hshr[i] + s[i] * pw[i] % mod) % mod;
}
long long get(int l, int r) {
  return ((hsh[r] - hsh[l] * pw[r - l] % mod) % mod + mod) % mod;
}
long long getr(int l, int r) {
  return ((hshr[r] - hshr[l]) % mod + mod) % mod * Pow(pw[l], mod - 2) % mod;
}
bool check(int i) {
  if (i + 1 < d) {
    return false;
  }
  long long h1 = get(i - d + 1, i + 1);
  long long h2 = getr(i - d + 1, i + 1);
  if (h1 == h2) {
    return true;
  }
  if (i < d) {
    return false;
  }
  long long h3 = get(i - d, i + 1);
  long long h4 = getr(i - d, i + 1);
  return (h3 == h4);
}
string next(string s) {
  int i = s.size() - 1;
  while (i >= 0 && s[i] == 'z') {
    i--;
  }
  if (i == -1) {
    return "*";
  }
  s[i]++;
  for (int j = i + 1; j <= i; j++) {
    s[j] = 'a';
  }
  return s;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> d >> s;
  int n = (int)s.size();
  pw[0] = 1;
  for (int i = 0; i <= n + 5; i++) {
    pw[i + 1] = pw[i] * base % mod;
  }
  for (int i = 0; i < n; i++) {
  }
  s = next(s);
  if (s == "*") {
    cout << "Impossible";
    return 0;
  }
  int x = -1;
  for (int i = 0; i < n; i++) {
    make(i);
    if (check(i)) {
      x = i;
      break;
    }
  }
  if (x == -1) {
    cout << s;
    return 0;
  }
  bool f = false;
  while (x >= 0 && !f) {
    while (s[x] < 'z') {
      s[x]++;
      make(x);
      if (!check(x)) {
        f = true;
        break;
      }
    }
    if (!f) {
      x--;
    }
  }
  if (!f) {
    cout << "Impossible";
    return 0;
  }
  for (int i = x + 1; i < n; i++) {
    s[i] = 'a';
    make(i);
    while (check(i)) {
      s[i]++;
      make(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] > 'z' || s[i] < 'a') {
      cout << "Impossible";
      return 0;
    }
  }
  cout << s;
  return 0;
}

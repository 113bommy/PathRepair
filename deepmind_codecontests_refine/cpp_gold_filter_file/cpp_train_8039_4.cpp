#include <bits/stdc++.h>
using namespace std;
long long Min(long long a, long long b) {
  if (a >= b)
    return b;
  else
    return a;
}
long long Max(long long a, long long b) {
  if (a >= b)
    return a;
  else
    return b;
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long power(long long x, long long y, long long m) {
  long long r = 1;
  x %= m;
  while (y > 0) {
    if (y % 2 != 0) {
      r = (r * x) % m;
    }
    y /= 2;
    x = (x * x) % m;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int i, n = s.length();
    if (s.length() == 1) {
      cout << s << endl;
      continue;
    }
    for (i = 0; i < (n / 2); i++) {
      if (s[i] != s[n - i - 1]) break;
    }
    long long x = i, m1 = 0, m2 = 0, j;
    string temp = "";
    for (i = x; i <= n - x - 1; i++) {
      temp.append(1, s[i]);
      for (j = 0; j < temp.length() / 2; j++) {
        if (temp[j] != temp[temp.length() - 1 - j]) break;
      }
      if (j == temp.length() / 2) {
        m1 = temp.length();
      }
    }
    temp = "";
    for (i = n - 1 - x; i >= x; i--) {
      temp.append(1, s[i]);
      for (j = 0; j < temp.length() / 2; j++) {
        if (temp[j] != temp[temp.length() - 1 - j]) break;
      }
      if (j == temp.length() / 2) {
        m2 = temp.length();
      }
    }
    string ans = "";
    if (m1 >= m2) {
      for (i = 0; i < x + m1; i++) ans.append(1, s[i]);
      for (i = n - x; i < n; i++) ans.append(1, s[i]);
    } else {
      for (i = 0; i < x; i++) ans.append(1, s[i]);
      for (i = n - x - m2; i < n; i++) ans.append(1, s[i]);
    }
    cout << ans << endl;
  }
  return 0;
}

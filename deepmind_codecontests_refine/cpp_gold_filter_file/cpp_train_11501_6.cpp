#include <bits/stdc++.h>
using namespace std;
int64_t mod = 1e9 + 7;
int64_t mult(int64_t n, int64_t k) {
  if (k == 1) {
    return n % mod;
  } else {
    if (k % 2 == 0) {
      int64_t ans = mult(n, k / 2);
      return (ans % mod + ans % mod) % mod;
    } else {
      int64_t ans = mult(n, k / 2);
      return ((ans % mod + ans % mod) + n % mod) % mod;
    }
  }
}
int64_t mul(int64_t n, int64_t k) {
  if (k == 0) {
    return 1;
  } else {
    if (k % 2 == 0) {
      int64_t ans = mul(n, k / 2);
      return mult(ans, ans);
    } else {
      int64_t ans = mul(n, k / 2);
      return mult(ans, mult(ans, n));
    }
  }
}
int64_t gcd(int64_t a, int64_t b) {
  if (b == 0) {
    return a;
  } else
    return gcd(b, a % b);
}
string add(string x, string y) {
  x.push_back('0');
  y.push_back('0');
  while (x.size() > y.size()) y.push_back('0');
  while (y.size() > x.size()) x.push_back('0');
  int cnt = 0;
  string res = "";
  for (int i = 0; i < x.size(); i++) {
    int ch = cnt + int(x[i]) + int(y[i]) - 96;
    cnt = ch / 10;
    res.push_back(char(ch % 10 + 48));
  }
  while (res[res.size() - 1] == '0') res.pop_back();
  return res;
}
string sub(string x, string y) {
  x.push_back('0');
  y.push_back('0');
  while (x.size() > y.size()) y.push_back('0');
  while (y.size() > x.size()) x.push_back('0');
  int cnt = 0;
  string res = "";
  for (int i = 0; i < x.size(); i++) {
    int ch = int(x[i]) - int(y[i]) - cnt + 10;
    cnt = 1 - ch / 10;
    res.push_back(char(ch % 10 + 48));
  }
  while (res[res.size() - 1] == '0') res.pop_back();
  return res;
}
void rev(string &a) { reverse(a.begin(), a.end()); }
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  int64_t m, s;
  cin >> m >> s;
  if (m * 9 < s)
    cout << -1 << " " << -1;
  else if (s == 0) {
    if (m == 1)
      cout << 0 << " " << 0;
    else
      cout << -1 << " " << -1;
  } else if (s % 9 == 0) {
    int nine = s / 9;
    int scscl = m - nine;
    string sobe = "";
    sobe = sobe + '1';
    if (scscl == 0) {
      for (int i = 1; i <= 2 * m; i++) {
        cout << '9';
        if (i == m) cout << " ";
      }
      return 0;
    } else {
      for (int i = 1; i <= scscl - 1; i++) sobe = sobe + '0';
      sobe = sobe + '8';
      for (int i = 1; i <= nine - 1; i++) sobe = sobe + '9';
    }
    cout << sobe << " ";
    for (int i = 1; i <= nine; i++) cout << '9';
    for (int i = 1; i <= scscl; i++) cout << '0';
  } else if (s < 9) {
    if (m == 1)
      cout << s << " " << s;
    else {
      cout << 1;
      m = m - 1;
      for (int i = 1; i <= m - 1; i++) cout << 0;
      cout << s - 1 << " ";
      cout << s;
      for (int i = 1; i <= m; i++) cout << 0;
    }
  } else {
    int nine = s / 9;
    int rem = s % 9;
    int scscl = m - nine;
    string sobe = "";
    if (scscl == 1) {
      sobe = sobe + char(rem + 48);
      scscl = 0;
    } else {
      sobe = sobe + '1';
      scscl -= 1;
      rem -= 1;
      for (int i = 1; i <= scscl - 1; i++) sobe = sobe + '0';
      sobe = sobe + char((s % 9 - 1) + 48);
    }
    for (int i = 1; i <= nine; i++) sobe = sobe + '9';
    cout << sobe << " ";
    for (int i = 1; i <= nine; i++) cout << 9;
    cout << s % 9;
    for (int i = 1; i <= scscl; i++) cout << 0;
  }
}

#include <bits/stdc++.h>
using namespace std;
string add(string a, string b) {
  string result = "";
  int s = 0;
  int i = a.size() - 1;
  while (i >= 0 || s == 1) {
    s += a[i] - '0';
    s += b[i] - '0';
    result = char(s % 2 + '0') + result;
    s /= 2;
    i--;
  }
  return result;
}
string subtract(string a, string b) {
  int res;
  string ans = "";
  int c = 0;
  for (int i = a.size() - 1; i >= 0; i--) {
    res = a[i] - b[i] - c;
    if (res < 0)
      c = 1;
    else
      c = 0;
    if (res == -1) res = 1;
    if (res == -2) res = 0;
    ans = char(res + '0') + ans;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  int n, m, i, j, g, l, net, net2, e;
  string s[105];
  while (t--) {
    string b = "", c = "", d;
    e = 0;
    cin >> n >> m;
    c = '0';
    g = l = 0;
    if (m > 1)
      for (i = 1; i < m; i++) c = c + '1';
    map<string, int> mp;
    for (i = 0; i < n; i++) {
      cin >> s[i];
      if (s[i] != c) mp[s[i]] = 1;
      if (s[i] < c)
        l++;
      else if (s[i] > c)
        g++;
      else
        e++;
    }
    if (m > 1)
      for (i = 0; i < m - 1; i++) b = b + '0';
    b = b + '1';
    d = c;
    net = (l + 1) / 2;
    if (l % 2 == 1)
      net = net - (g + 1) / 2;
    else
      net = net - g / 2;
    if (net > 0) {
      while (net) {
        c = add(c, b);
        if (mp.count(c) == 0) net--;
      }
    } else if (net < 0) {
      net *= -1;
      while (net) {
        c = subtract(c, b);
        if (mp.count(c) == 0) net--;
      }
    }
    if (e == 1 && (l + g) % 2 == 0) {
      if (d <= c) {
        while (1) {
          c = add(c, b);
          if (mp.count(c) == 0) break;
        }
      }
    } else if (e == 1 && (l + g) % 2 == 1 && c <= d) {
      while (1) {
        c = subtract(c, b);
        if (mp.count(c) == 0) break;
      }
    }
    cout << c << endl;
  }
  return 0;
}

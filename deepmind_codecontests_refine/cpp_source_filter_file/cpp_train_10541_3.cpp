#include <bits/stdc++.h>
using namespace std;
string i_s(int x) {
  if (x == 0) return "0";
  string ret = "";
  while (x) {
    ret = ret + (char)(x % 10 + '0');
    x /= 10;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
string add(string a, string b) {
  if (a == "") a = "0";
  if (b == "") b = "0";
  if (a.length() < b.length()) swap(a, b);
  while (b.length() < a.length()) {
    b = '0' + b;
  }
  for (int i = 0; i < a.length(); i++) {
    a[i] = a[i] + (b[i] - '0');
  }
  bool big = false;
  for (int i = a.length() - 1; i >= 0; i--) {
    if (big) {
      a[i]++;
    }
    big = false;
    if (a[i] > '9') {
      a[i] = a[i] - 10;
      big = true;
    }
  }
  if (big) a = '1' + a;
  return a;
}
string mul(string a, string b) {
  vector<int> va, vb;
  if (a == "0" || b == "0") return "0";
  string ans;
  for (int i = 0; i < a.length(); i++) {
    va.push_back(a[i] - '0');
  }
  for (int i = 0; i < b.length(); i++) {
    vb.push_back(b[i] - '0');
  }
  reverse(va.begin(), va.end());
  reverse(vb.begin(), vb.end());
  vector<int> res;
  res.clear();
  res.resize(1005);
  for (int i = 0; i < a.length(); i++) {
    for (int j = 0; j < b.length(); j++) {
      res[i + j] += (va[i] * vb[j]);
    }
  }
  for (int i = 0; i < 1005; i++) {
    if (res[i] > 9) {
      res[i + 1] += (res[i] / 10);
      res[i] %= 10;
    }
  }
  for (int i = 0; i < 1005; i++) {
    ans += (res[i] + '0');
  }
  reverse(ans.begin(), ans.end());
  int k = 0;
  while (ans[k] == '0') {
    k++;
  }
  ans = ans.substr(k);
  return ans;
}
bool is_prime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
int f[505][505];
int g[505][505];
int p[505][505];
char s[505];
int n, m;
void rec(int i, int j) {
  if (i == 0) return;
  rec(p[i][j], j - 1);
  if (p[i][j]) cout << "+";
  for (int k = 0; k < i - p[i][j]; k++)
    cout << ((s[p[i][j] + 1 + k] != s[i - k] && p[i][j] + 1 + k < i - k)
                 ? s[i - k]
                 : s[p[i][j] + 1 + k]);
  return;
}
int main() {
  gets(s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = 0;
      for (int k = 0; k < (j - i + 1) / 2; k++) {
        f[i][j] += s[i + k] != s[j - k];
      }
    }
  }
  cin >> m;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) g[i][j] = 0x3f3f3f3f;
  g[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] < 0x3f3f3f3f) {
        for (int k = i + 1; k <= n; k++) {
          if (g[i][j] + f[i + 1][k] < g[k][j + 1]) {
            g[k][j + 1] = g[i][j] + f[i + 1][k];
            p[k][j + 1] = i;
          }
        }
      }
    }
  }
  int x = 0;
  for (int i = 1; i <= m; i++) {
    if (g[n][i] < g[n][x]) {
      x = i;
    }
  }
  cout << g[n][x];
  rec(n, x);
  return 0;
}

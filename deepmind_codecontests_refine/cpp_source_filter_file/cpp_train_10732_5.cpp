#include <bits/stdc++.h>
using namespace std;
inline void print(int n) {
  if (n == 0) {
    putchar('0');
    putchar('\n');
  } else if (n == -1) {
    putchar('-');
    putchar('1');
    putchar('\n');
  } else {
    char buf[11];
    buf[10] = '\n';
    int i = 9;
    while (n) {
      buf[i--] = n % 10 + '0';
      n /= 10;
    }
    while (buf[i] != '\n') putchar(buf[++i]);
  }
}
int read() {
  int cc = getc(stdin);
  for (; cc < '0' || cc > '9';) cc = getc(stdin);
  int ret = 0;
  for (; cc >= '0' && cc <= '9';) {
    ret = ret * 10 + cc - '0';
    cc = getc(stdin);
  }
  return ret;
}
string read1() {
  int cc = getc(stdin);
  for (; cc < '0' || cc > '9';) cc = getc(stdin);
  string r = "";
  for (; cc >= '0' && cc <= '9';) {
    r += cc;
    cc = getc(stdin);
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  int m;
  string s, t;
  cin >> n >> m >> s >> t;
  if (n - 1 > m) {
    cout << "NO\n";
    return 0;
  }
  if (m + 1 == n) {
    bool is = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == '*') is = true;
    }
    if (!is) {
      cout << "NO\n";
      return 0;
    }
  }
  int i = 0, j = 0;
  bool is = false;
  while (i < n) {
    if (s[i] == t[j])
      i++, j++;
    else if (s[i] == '*')
      break;
    else {
      cout << "NO\n";
      return 0;
    }
  }
  i = n - 1, j = m - 1;
  while (i >= 0) {
    if (s[i] == t[j])
      i--, j--;
    else if (s[i] == '*') {
      cout << "YES\n";
      return 0;
    } else {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}

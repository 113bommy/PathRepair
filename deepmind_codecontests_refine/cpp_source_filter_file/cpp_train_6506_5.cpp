#include <bits/stdc++.h>
using namespace std;
int n, m, l;
string s;
inline int read() {
  int sum = 0, fh = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum *= 10;
    sum += c - '0';
    c = getchar();
  }
  return sum * fh;
}
int now;
long long rs;
int main() {
  n = read();
  m = read();
  cin >> s;
  l = s.size();
  rs = 1ll * n * (m - 1);
  for (int i = 1; i < n; i++) {
    if (i >= 2 && s[i] == s[i - 1])
      now++;
    else
      now = 0;
    if (s[i] != s[i - 1]) {
      rs += 1ll * n * (m - 1) - now - 1;
    }
  }
  cout << rs << endl;
  return 0;
}

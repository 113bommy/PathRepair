#include <bits/stdc++.h>
using namespace std;
int all = 0;
int d[10000];
int main() {
  int n, i, m;
  cin >> n;
  string str;
  int cnt = 0, len = 0;
  while (cin >> str) {
    m = str.length();
    ++cnt;
    len += m;
    if (str[m - 1] == '.' || str[m - 1] == '?' || str[m - 1] == '!') {
      d[++all] = len + (cnt - 1);
      if (d[all] > n) {
        cout << "Impossible";
        return 0;
      }
      cnt = 0;
      len = 0;
    }
  }
  int ret = 0, add;
  len = cnt = 0;
  for (i = 1; i <= all; ++i) {
    if (!len)
      add = 0;
    else
      add = 1;
    if (d[i] + len + add <= n) {
      len += d[i] + add;
    } else {
      ++ret;
      len = d[i];
      if (len == n) {
        len = 0;
        ++ret;
      }
    }
  }
  if (len) ++ret;
  cout << ret;
  return 0;
}

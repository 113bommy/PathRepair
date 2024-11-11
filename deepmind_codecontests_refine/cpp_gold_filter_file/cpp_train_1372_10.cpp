#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN], n, q, p, x;
map<int, pair<int, int> > opt1;
int opt2[MAXN];
int read() {
  int s = 1, x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') s = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = 10 * x + ch - '0';
    ch = getchar();
  }
  return x * s;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  q = read();
  int id;
  for (int i = 1; i <= q; ++i) {
    id = read();
    if (id == 1) {
      p = read(), x = read();
      if (opt1.count(p))
        opt1[p] = make_pair(x, i);
      else
        opt1.insert(make_pair(p, make_pair(x, i)));
    } else if (id == 2) {
      x = read();
      opt2[i] = x;
    }
  }
  for (int i = q; i >= 1; --i) opt2[i] = max(opt2[i], opt2[i + 1]);
  for (int i = 1; i <= n; ++i) {
    if (opt1.count(i))
      a[i] = max(opt1[i].first, opt2[opt1[i].second + 1]);
    else
      a[i] = max(a[i], opt2[1]);
    cout << a[i] << ' ';
  }
  return 0;
}

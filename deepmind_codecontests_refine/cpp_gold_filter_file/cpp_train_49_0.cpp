#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long ret = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
  return ret * f;
}
long long n;
string f = "", g = "";
string get_string(long long x, long long i) {
  string ret = "(" + to_string(x) + "*((1-abs((t-" + to_string(i) +
               ")))+abs((1-abs((t-" + to_string(i) + "))))))";
  return ret;
}
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) {
    long long x = read(), y = read(), r = read();
    if (i == 1) {
      f = get_string(x / 2, i);
      g = get_string(y / 2, i);
    } else {
      f = "(" + f + "+" + get_string(x / 2, i) + ")";
      g = "(" + g + "+" + get_string(y / 2, i) + ")";
    }
  }
  cout << f << endl << g << endl;
  return 0;
}

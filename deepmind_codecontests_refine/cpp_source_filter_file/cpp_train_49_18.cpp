#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (ch > '9' || ch < '0');
  do {
    x = x * 10 + ch - '0';
    ch = getchar();
  } while (ch <= '9' && ch >= '0');
  return f * x;
}
const int maxn = 55;
int x[maxn], y[maxn], r[maxn];
int main() {
  string left = "(((1-abs((t-", mid = ")))+abs((abs((t-", right = "))-1)))";
  string ans1 = "";
  string ans2 = "";
  int n = read();
  for (int i = 0; i < n; i++) {
    x[i] = read(), y[i] = read(), r[i] = read();
  }
  for (int i = 0; i < n - 1; i++) {
    ans1 += "(";
    ans2 += "(";
  }
  for (int i = 0; i < n; i++) {
    string num = to_string(i);
    ans1 += left + num + mid + num + right + "*" + to_string(x[i] / 2) + ")";
    ans2 += left + num + mid + num + right + "*" + to_string(y[i] / 2) + ")";
    if (i != 0) ans2 = ")", ans1 += ")";
    if (i != n - 1) ans1 += "+", ans2 += "+";
  }
  cout << ans1 << endl;
  cout << ans2 << endl;
  return 0;
}

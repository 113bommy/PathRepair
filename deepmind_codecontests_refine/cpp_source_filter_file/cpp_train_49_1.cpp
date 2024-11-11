#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void Min(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline void Max(T &a, T b) {
  if (a < b) a = b;
}
string s, ans, res;
void cal(string &s, int first, int i) {
  s.clear();
  int n = 0;
  s += "(";
  first /= 2;
  char b[10];
  int m = 0;
  while (first > 0) b[m++] = first % 10 + '0', first /= 10;
  if (m == 0) b[m++] = '0';
  for (int i = m - 1; i >= 0; i--) s += b[i];
  s += "*";
  string t = "t-";
  first = i;
  m = 0;
  while (first > 0) b[m++] = first % 10 + '0', first /= 10;
  if (m == 0) b[m++] = '0';
  for (int i = m - 1; i >= 0; i--) t += b[i];
  t = "abs((" + t + "))";
  s += "((1-" + t + ")abs((" + "-1))))";
}
int main() {
  int T, i, j, k, n, m;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    int first, second;
    scanf("%d%d%d", &first, &second, &k);
    cal(s, first, i);
    if (i)
      ans = "(" + ans + "+" + s + ")";
    else
      ans = s;
    cal(s, second, i);
    if (i)
      res = "(" + res + "+" + s + ")";
    else
      res = s;
  }
  cout << ans << "\n" << res << "\n";
  return 0;
}

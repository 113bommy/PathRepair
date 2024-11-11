#include <bits/stdc++.h>
using namespace std;
template <class _Tp>
_Tp gcd(_Tp a, _Tp b) {
  return (b == 0) ? (a) : (gcd(b, a % b));
}
const long long Inf = 1000000000000000000ll;
const int inf = 1000000000;
char buf[1 << 25], *p1 = buf, *p2 = buf;
inline int getc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 25, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int x = 0, f = 0;
  char c = getc();
  while (!isdigit(c)) (c == '-') && (f = 1), c = getc();
  while (isdigit(c)) x = x * 10 + (c & 15), c = getc();
  return f ? -x : x;
}
vector<int> num;
int n;
vector<int> solve(int step) {
  if (step > 18) return vector<int>(0);
  bool check = 0;
  for (vector<int>::iterator it = num.begin(); it != num.end(); ++it)
    if (*it & 1) {
      check = 1;
      break;
    }
  if (!check) {
    for (vector<int>::iterator it = num.begin(); it != num.end(); ++it)
      *it /= 2;
    return solve(step + 1);
  }
  vector<int> t = num;
  for (vector<int>::iterator it = num.begin(); it != num.end(); ++it)
    if (*it & 1)
      *it = (*it + 1) / 2;
    else
      *it /= 2;
  sort(num.begin(), num.end());
  num.erase(unique(num.begin(), num.end()), num.end());
  vector<int> res1 = solve(step + 1);
  res1.push_back(-(1 << step));
  num = t;
  for (vector<int>::iterator it = num.begin(); it != num.end(); ++it)
    if (*it & 1)
      *it = (*it - 1) / 2;
    else
      *it /= 2;
  sort(num.begin(), num.end());
  num.erase(unique(num.begin(), num.end()), num.end());
  vector<int> res2 = solve(step + 1);
  res2.push_back(1 << step);
  return res1.size() < res2.size() ? res1 : res2;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) num.push_back(read());
  vector<int> ans = solve(0);
  printf("%d\n", ans.size());
  for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
    printf("%d ", *it);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool f[(1 << 17)];
int a, b, c, d;
vector<int> u, v;
long long Calc(long long x) { return x * (x - 1) / 2; }
int GetCount(long long x) {
  long long L = 0, R = (1 << 17);
  if (x == 0) return 0;
  for (; L < R;) {
    long long mid = ((L + R) >> 1) + 1;
    if (Calc(mid) <= x)
      L = mid;
    else
      R = mid - 1;
  }
  if (Calc(L) != x)
    return -1;
  else
    return L;
}
bool judge(int x, int y, int b, int c) {
  if (x + y == 0) return 0;
  if (Calc(x) + Calc(y) + b + c != Calc(x + y)) return 0;
  for (int i = 1; i <= y; i++) {
    int t = b / (y - i + 1);
    f[t + i - 1] = 1, b -= t;
  }
  for (int i = 0; i < x + y; i++) putchar(48 + f[i]);
  putchar('\n');
  return 1;
}
int main() {
  cin >> a >> b >> c >> d;
  int x = GetCount(a), y = GetCount(d);
  if (x == 0)
    u.push_back(0), u.push_back(1);
  else
    u.push_back(x);
  if (y == 0)
    v.push_back(0), v.push_back(1);
  else
    v.push_back(y);
  if (x == -1 || y == -1)
    puts("Impossible");
  else {
    for (int i = 0; i < u.size(); i++)
      for (int j = 0; j < v.size(); j++)
        if (judge(u[i], v[j], b, c)) return 0;
    puts("Impossible");
  }
}

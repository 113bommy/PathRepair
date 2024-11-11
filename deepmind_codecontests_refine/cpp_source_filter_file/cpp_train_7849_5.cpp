#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T1, class T2>
T1 cal(T1 zero, T1 x, T2 y) {
  T1 ret = zero, z = x;
  for (T1 i = 1; i <= y; i <<= (T2)1, z *= z) i& y ? ret *= z : 0;
  return ret;
}
int n;
set<int> s;
int main() {
  int i;
  scanf("%d", &n);
  s.insert(1);
  for (i = 2; s.size() < n; i++)
    for (__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
      if ((*it) * i <= n * n / 3) s.insert((*it) * i);
  for (__typeof(s.rbegin()) it = s.rbegin(); n--; it++)
    printf("%d%c", *it, n == 0 ? '\n' : ' ');
}

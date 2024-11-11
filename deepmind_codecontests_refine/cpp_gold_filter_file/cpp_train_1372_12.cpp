#include <bits/stdc++.h>
int read() {
  int k = 0, flag = 1;
  char tmp = getchar();
  while ('0' > tmp || '9' < tmp) {
    if (tmp == '-') flag = -1;
    tmp = getchar();
  }
  while ('0' <= tmp && '9' >= tmp) {
    k = 10 * k + tmp - '0';
    tmp = getchar();
  }
  return flag * k;
}
const int maxn = 200005;
int n, qq, high;
int mem[maxn], tim[maxn], a[maxn];
std::vector<int> v1, v2;
signed main() {
  std::memset(tim, -1, sizeof(tim));
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  qq = read();
  for (int q = 1; q <= qq; ++q) {
    if (read() == 2) {
      high = read();
      while (v1.size() && v1[v1.size() - 1] < high)
        v1.pop_back(), v2.pop_back();
      v1.push_back(high);
      v2.push_back(q);
    } else {
      int i = read(), x = read();
      tim[i] = q;
      mem[i] = x;
    }
  }
  v1.push_back(0);
  v2.push_back(qq + 1);
  for (int i = 1; i <= n; ++i) {
    if (tim[i] == -1)
      printf("%d ", std::max(v1[0], a[i]));
    else {
      int k = std::upper_bound(v2.begin(), v2.end(), tim[i]) - v2.begin();
      printf("%d ", std::max(v1[k], mem[i]));
    }
  }
  return 0;
}

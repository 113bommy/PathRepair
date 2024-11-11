#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int n, d[N], l, r, L, R;
vector<pair<int, int> > ans;
inline int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
int main() {
  n = read();
  for (int i = (1), iend = (n); i <= iend; i++) d[i] = read();
  l = 1, r = n, L = 1, R = d[n] + 1;
  while (l <= r) {
    for (int i = (L), iend = (L + d[l] - 1); i <= iend; i++)
      for (int j = (i + 1), jend = (R); j <= jend; j++)
        ans.push_back(make_pair(i, j));
    L += d[l], R = d[r - 1] + 1;
    for (int i = (l + 1), iend = (r - 1); i <= iend; i++) d[i] -= d[l];
    l++, r--;
  }
  printf("%d\n", ans.size());
  for (auto x : ans) printf("%d %d\n", x.first, x.second);
  return 0;
}

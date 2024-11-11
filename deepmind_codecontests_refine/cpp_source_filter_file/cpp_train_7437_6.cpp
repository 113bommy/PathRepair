#include <bits/stdc++.h>
using namespace std;
int getint() {
  int s = 0;
  char c;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar()) s *= 10, s += c - '0';
  return s;
}
const int maxn = 100010;
int n, m, k;
std::vector<int> v[2], b[maxn];
int main(int argc, char const *argv[]) {
  n = getint(), m = getint(), k = getint();
  for (int i = 0; i < n; i++) {
    int x = getint();
    v[x & 1].push_back(x);
  }
  k = m - k;
  if (k % 2 == (v[1]).size() % 2 && (v[1]).size() >= k &&
      v[0].size() + v[1].size() / 2 >= m - k) {
    for (int i = 0; i < k; i++) b[i].push_back(v[1][i]);
    for (int i = k % m, j0 = 0, j1 = k;
         j0 < (v[0]).size() || j1 < (v[1]).size(); i++, i %= m) {
      if (j0 < (v[0]).size()) {
        b[i].push_back(v[0][j0++]);
      } else {
        b[i].push_back(v[1][j1++]);
        b[i].push_back(v[1][j1++]);
      }
    }
    printf("YES\n");
    for (int i = 0; i < m; i++) {
      printf("%d", b[i].size());
      for (int j = 0; j < b[i].size(); j++) printf(" %d", b[i][j]);
      printf("\n");
    }
  } else
    printf("NO\n");
  return 0;
}

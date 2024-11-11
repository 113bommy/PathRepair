#include <bits/stdc++.h>
using namespace std;
void err() { cerr << "\n"; }
template <class T, class... Ts>
void err(const T& arg, const Ts&... args) {
  cerr << arg << ' ';
  err(args...);
}
inline int rd() {
  int f = 0;
  int x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
  if (f) x = -x;
  return x;
}
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
char s[300007];
int pre[300007][2][2], tmp[2][2];
int get(int i) {
  if (s[i] == '+') return 1;
  return 0;
}
void solve() {
  int n = rd(), q = rd();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        if ((i & 1) == k && get(i) == j)
          pre[i][j][k] = 1;
        else
          pre[i][j][k] = 0;
        pre[i][j][k] += pre[i - 1][j][k];
      }
    }
  }
  while (q--) {
    int l = rd(), r = rd();
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        tmp[j][k] = pre[r][j][k] - pre[l - 1][j][k];
      }
    }
    if (l % 2 == 0) {
      swap(tmp[0][0], tmp[0][1]);
      swap(tmp[1][0], tmp[1][1]);
    }
    if (tmp[0][0] == tmp[0][1] && tmp[1][0] == tmp[1][1]) {
      puts("0");
    } else {
      int sum0 = tmp[0][0] + tmp[0][1], sum1 = tmp[1][0] + tmp[1][1];
      if (sum0 % 2 == 0 && sum1 % 2 == 0) {
        puts("2");
      } else {
        printf("%d\n", (sum0 & 1) + (sum1 & 1));
      }
    }
  }
}
int main() {
  int t = 1;
  t = rd();
  while (t--) solve();
  return 0;
}

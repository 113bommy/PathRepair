#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long mod = 9973;
inline long long read() {
  long long X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
long long n, m, k;
long long ar[N], br[N];
long long ans;
char ch[N];
int as[N];
int an[30];
void solve() {
  n = read();
  m = read();
  scanf("%s", ch + 1);
  for (register int i(0); i <= 30; ++i) an[i] = 0;
  for (register int i(0); i <= m + 10; ++i) as[i] = 0;
  for (register int i(1); i <= m; ++i) {
    int t = read();
    as[1]++;
    as[t + 1]--;
  }
  int t = 0;
  for (register int i(1); i <= n; ++i) {
    t += as[i];
    an[ch[i] - 'a'] += t + 1;
  }
  for (register int i(0); i <= 25; ++i) printf("%d ", an[i]);
  puts("");
}
int main() {
  int T;
  T = read();
  while (T--) {
    solve();
  }
  return 0;
}

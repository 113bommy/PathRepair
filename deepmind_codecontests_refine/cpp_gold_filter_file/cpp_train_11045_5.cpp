#include <bits/stdc++.h>
using namespace std;
const int N = 510, Mo = 1000000007;
int d[N], c[N];
inline int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int main() {
  int n;
  cin >> n;
  for (int i = d[0] = 1; i <= n; i++) d[i] = 2 * d[i - 1] % Mo;
  for (int i = 1; i <= n; i++) {
    int x = gi();
    if (x != -1) ++c[x];
  }
  int ans = d[n - 1] - 1;
  for (int i = 1; i <= n; i++) ans = (ans - d[c[i]] + 1) % Mo;
  cout << (ans + Mo) % Mo;
  return 0;
}

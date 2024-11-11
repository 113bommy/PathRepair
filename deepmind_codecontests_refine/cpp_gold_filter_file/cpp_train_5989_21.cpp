#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
int n;
int l[MAXN], h[MAXN];
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int main() {
  cin >> n;
  char tmp;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> tmp;
      if (tmp == 'C') l[i]++, h[j]++;
    }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans += l[i] * (l[i] - 1) / 2 + h[i] * (h[i] - 1) / 2;
  cout << ans << "\n";
  return 0;
}

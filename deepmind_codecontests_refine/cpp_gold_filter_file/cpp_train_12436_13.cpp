#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int MAXM = 2e5 + 10;
int n, m;
int s[MAXN];
int t[MAXM];
int kmp[MAXM];
int main() {
  scanf("%d%d", &n, &m);
  if (m == 1) return printf("%d\n", n), 0;
  if (n == 1) return printf("%d\n", m == 1 ? 1 : 0), 0;
  static vector<int> a(max(n, m) + 1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= n; i++) s[i - 1] = a[i] - a[i - 1];
  for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= m; i++) t[i - 1] = a[i] - a[i - 1];
  n--;
  m--;
  kmp[1] = 0;
  for (int i = 2; i <= m; i++) {
    int j = kmp[i - 1];
    while (j && t[i] != t[j + 1]) j = kmp[j];
    if (t[i] == t[j + 1]) j++;
    kmp[i] = j;
  }
  int pos = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    while (pos && s[i] != t[pos + 1]) pos = kmp[pos];
    if (s[i] == t[pos + 1]) pos++;
    if (pos == m) ans++, pos = kmp[pos];
  }
  printf("%d\n", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
char a[maxn], b[maxn];
int sum[maxn];
int main() {
  scanf(" %s", a);
  int la = strlen(a);
  scanf(" %s", b);
  int lb = strlen(b);
  for (int i = 0; i < la; i++) {
    if (i > 0) sum[i] = sum[i - 1];
    if (a[i] == '1') sum[i]++;
  }
  int cntb = 0;
  for (int i = 0; i < lb; i++)
    if (b[i] == '1') cntb++;
  int ans = 0;
  for (int i = 0; i <= la - lb; i++) {
    int cnta = 0;
    if (i > 0)
      cnta = sum[i + lb - 1] - sum[i - 1];
    else
      cnta = sum[i + lb - 1];
    if (cnta % 2 == cntb % 2) ans++;
  }
  printf("%d\n", ans);
  return 0;
}

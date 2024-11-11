#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 6;
int n;
char ch[MAXN];
int L[2][MAXN], l[MAXN];
signed main() {
  cin >> n;
  scanf("%s", ch + 1);
  L[0][0] = L[1][0] = l[0] = 1;
  for (int i = 1, iend = n; i <= iend; ++i) {
    if (ch[i] != '?') {
      int w = ch[i] - '0';
      L[w][i] = L[w][i - 1], L[w ^ 1][i] = i + 1, l[i] = L[w][i];
    } else {
      for (int w = 0, wend = 1; w <= wend; ++w) L[w][i] = L[w][i - 1];
      l[i] = l[i - 1];
    }
  }
  printf("%d ", n);
  for (int k = 1, kend = n - 1; k <= kend; ++k) {
    int as = 0;
    int i = 1;
    while (i + k <= n) {
      if (l[i + k] <= i) {
        i += k + 1, ++as;
      } else {
        i = l[i + k];
      }
    }
    printf("%d ", as);
  }
}

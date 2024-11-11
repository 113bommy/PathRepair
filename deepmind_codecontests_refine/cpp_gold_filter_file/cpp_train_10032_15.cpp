#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000000000000000LL;
const double EPS = 1e-9;
const long long mod = 1000000007ll;
const int maxn = 300500;
int a[maxn];
int nxt[maxn][32];
bool ha[8000500];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); ++i) scanf("%d", &a[i + 1]);
  for (int i = n; i > 0; i--) {
    for (int j = 0; j < (int)(32); ++j) {
      if ((1 << j) & a[i])
        nxt[i][j] = i;
      else
        nxt[i][j] = nxt[i + 1][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) ha[0] = 1;
    int cur = 0, curi = i;
    while (true) {
      int nxti = 123456789;
      for (int j = 0; j < (int)(32); ++j)
        if (!((1 << j) & cur) && nxt[curi][j]) {
          nxti = min(nxti, nxt[curi][j]);
        }
      if (nxti == 123456789) break;
      cur |= a[nxti];
      curi = nxti;
      ha[cur] = 1;
    }
  }
  int ret = 0;
  for (int i = 0; i < 8000500; i++) ret += ha[i];
  printf("%d", ret);
}

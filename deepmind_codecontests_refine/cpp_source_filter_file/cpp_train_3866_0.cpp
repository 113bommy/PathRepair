#include <bits/stdc++.h>
using namespace std;
const int INT_INF = 1e9;
const long long LL_INF = 1e18;
const int MAXN = 2000003;
typedef struct GE {
  int to;
  long long w;
  GE(){};
} GE;
int n, m;
char s[MAXN];
int f[MAXN], r[MAXN];
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  int ocnt = 0;
  for (int i = 1; i <= n; i++) {
    if (ocnt >= 0) {
      if (s[i] == '(')
        ocnt++;
      else
        ocnt--;
    }
    f[i + 1] = ocnt;
  }
  ocnt = 0;
  for (int i = n; i >= 1; i--) {
    if (ocnt >= 0) {
      if (s[i] == ')')
        ocnt++;
      else
        ocnt--;
    }
    r[i - 1] = ocnt;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '(') {
      if (r[i] != -1 && f[i] == r[i] + 1) cnt++;
    } else {
      if (f[i] != -1 && r[i] + 1 == f[i]) cnt++;
    }
  }
  printf("%d", cnt);
  return 0;
}

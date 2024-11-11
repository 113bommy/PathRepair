#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
int n, m, k;
int a[maxn], c[maxn];
int ans, tmp, cnt;
int flag;
char s[maxn];
bool ok[maxn];
int main() {
  int T, cas = 1;
  scanf("%d", &T);
  while (T--) {
    vector<int> vc, vv;
    scanf("%d", &n);
    memset(c, 0, sizeof(c));
    ans = 0;
    flag = 0;
    for (register int i = (1); i <= (n); i++) {
      scanf("%d", &a[i]);
      if (a[i] & 1)
        vc.push_back(i);
      else
        vv.push_back(i);
    }
    if (vv.size()) {
      puts("1");
      printf("%d\n", vv[0]);
    } else if (vc.size() > 1) {
      puts("2");
      printf("%d %d\n", vc[0], vc[1]);
    } else
      puts("-1");
  }
  return 0;
}

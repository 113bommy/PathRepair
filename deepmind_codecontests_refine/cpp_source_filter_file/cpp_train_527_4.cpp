#include <bits/stdc++.h>
using namespace std;
const int maxn = 4 * 1e5 + 10;
const long long mod = 998244353;
char st[maxn];
char ans[maxn];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  scanf("%s", st);
  int len = strlen(st);
  sort(st, st + len);
  int le = 0;
  ans[le++] = st[0];
  for (int i = 1; i < len; ++i) {
    if (st[i] != st[le - 1] + 1) {
      ans[le++] = st[i];
    }
  }
  int res = 0;
  if (le < k) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < k; ++i) {
    res += ans[i] - 'a' + 1;
  }
  printf("%d\n", res);
}

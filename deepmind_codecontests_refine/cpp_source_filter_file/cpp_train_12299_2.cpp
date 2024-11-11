#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t[N], fl[N], n, C, D;
long long ans;
char s[N];
int main() {
  scanf("%d%d%d", &n, &C, &D);
  for (int i = (int)(1); i <= (int)(n); i++) {
    scanf("%d%s", &t[i], s + 1);
    t[i] *= C;
    fl[i] = (s[1] == 'P');
  }
  scanf("%d", &t[n + 1]);
  t[n + 1] *= C;
  fl[n + 1] = -1;
  long long ans = D * n, s = 0;
  int las = t[n + 1];
  for (int i = (int)(n); i >= (int)(1); i--) {
    if (fl[i] == fl[i + 1])
      s += min(D, las - t[i + 1]);
    else {
      s += las - t[i + 1];
      las = t[i + 1];
    }
    ans = min(ans, las - t[i] + 1ll * D * (i - 1) + s);
  }
  printf("%lld\n", ans);
}

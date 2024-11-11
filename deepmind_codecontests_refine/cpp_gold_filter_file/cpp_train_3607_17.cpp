#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10, mod = 1e9 + 7, inf = 0x3f3f3f3f;
int n, m, k, t, cnt[26];
char a[maxn], b[maxn];
int main() {
  int i, j;
  scanf("%d%s%s", &n, a, b);
  for (i = 0; i < n; i++) {
    cnt[a[i] - 'a']++;
    cnt[b[i] - 'a']--;
  }
  for (i = 0; i < 26; i++)
    if (cnt[i]) return 0 * puts("-1");
  vector<int> ret;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i; j++)
      if (a[j] == b[i]) break;
    ret.push_back(n - j - 1);
    ret.push_back(1);
    ret.push_back(n);
    for (k = j; k < n - 1; k++) a[k] = a[k + 1];
    reverse(a, a + j);
  }
  printf("%d\n", 3 * n);
  for (auto &x : ret) printf("%d ", x);
  return 0;
}

#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int a[26];
char s[100010];
int main() {
  int T, i, j, k, ca = 0, n, m;
  for (i = 0; i < 26; i++) scanf("%d", &a[i]);
  scanf("%s", s);
  n = strlen(s);
  map<int, long long> g[26];
  long long ans = 0, f = 0;
  for (i = 0; i < n; i++)
    ans += g[s[i] - 'a'][f], f = f + a[s[i] - 'a'], g[s[i] - 'a'][f]++;
  printf("%I64d\n", ans);
}

#include <bits/stdc++.h>
using namespace std;
long long w[27], a, p;
map<long long, int> m[256];
int main() {
  for (int i = 0; i < 26; i++) scanf("%lld", &w[i]);
  char s[100005];
  scanf("%s", s + 1);
  for (int i = 1; s[i]; i++) a += m[s[i]][p], p += w[s[i] - 'a'], m[s[i]][p]++;
  printf("%lld\n", a);
  return 0;
}

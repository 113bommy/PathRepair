#include <bits/stdc++.h>
using namespace std;
int n, K;
char s[666], t[666];
inline bool check(int x) {
  for (int i = 0; i <= x; ++i)
    if (s[i] != s[n - x - 1 + i]) return false;
  return true;
}
int main() {
  scanf("%d%d%s", &n, &K, s);
  int len = 0;
  for (int i = 0; i < n - 1; ++i)
    if (check(i)) len = i + 1;
  int tot = 0;
  for (int i = 0; i < K; ++i)
    for (int j = 0; j < n - len; ++j) t[tot++] = s[j];
  for (int j = n - len; j < n; ++j) t[tot++] = s[j];
  puts(t);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T t) {
  return t < 0 ? -t : t;
}
const long long modn = 1000000007;
inline long long mod(long long x) { return x % modn; }
const int N = 200005;
int n;
int f[N], s[N], p[N];
int main() {
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &f[i]);
  for (i = 0; i < n; i++) scanf("%d", &s[i]), p[s[i]] = i + 1;
  for (i = 0; i < n; i++) s[i] = p[f[i]];
  for (i = 1; i < n; i++)
    if (s[i] < s[i - 1]) break;
  printf("%d\n", n - i);
  return 0;
}

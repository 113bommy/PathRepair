#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a, b, c, f[N];
vector<int> s;
int inv[N], g[N], h[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", f + i);
    if (f[i] == i) s.push_back(i);
  }
  bool ok = true;
  for (int i = 1; i <= n; ++i)
    if (f[f[i]] != i) ok = false;
  int len = s.size();
  if (len == 0 and ok) {
    puts("-1");
    return 0;
  }
  printf("%d\n", len);
  int t = 1;
  for (int it : s) inv[it] = t++;
  for (int i = 1; i <= n; ++i) g[i] = inv[f[i]];
  for (int i = 1; i <= n; ++i) printf("%d ", g[i]);
  puts("");
  for (int i = 1; i <= len; ++i) printf("%d ", s[i - 1]);
  puts("");
  return 0;
}

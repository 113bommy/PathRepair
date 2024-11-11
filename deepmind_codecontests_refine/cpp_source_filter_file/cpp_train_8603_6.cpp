#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1000000007;
char a[maxn], b[maxn];
char mm = 255;
bool vis[256];
int n, k;
char find(char x) {
  while (++x <= 'z')
    if (vis[x]) return x;
  return 'z' + 1;
}
int main() {
  cin >> n >> k;
  cin >> a + 1;
  memcpy(b + 1, a + 1, k);
  for (int i = 1; i <= n; ++i) vis[a[i]] = true, mm = min(mm, a[i]);
  if (k > n) {
    for (int i = n + 1; i <= k; ++i) b[i] = mm;
    cout << b + 1 << endl;
    return 0;
  }
  for (int i = k; i >= 1; --i) {
    char c = find(b[i]);
    if (c <= 'z')
      b[i] = c;
    else
      continue;
    for (int j = i + 1; j <= k; ++j) b[j] = mm;
    cout << b + 1 << endl;
    return 0;
  }
  return 0;
}

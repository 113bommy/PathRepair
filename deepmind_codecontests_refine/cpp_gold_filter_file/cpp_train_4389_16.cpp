#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int aa[maxn];
int bb[maxn];
int ans[maxn];
int main() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) aa[i] = a[i - 1] - 'a';
  for (int i = 1; i <= n; i++) bb[i] = b[i - 1] - 'a';
  for (int i = n; i >= 1; i--) {
    ans[i] += aa[i] + bb[i];
    ans[i - 1] += ans[i] / 26;
    ans[i] %= 26;
  }
  for (int i = 0; i <= n; i++) {
    if (ans[i] & 1) ans[i + 1] += 26;
    ans[i] >>= 1;
  }
  for (int i = 1; i <= n; i++) printf("%c", ans[i] + 'a');
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int p[32];
bool insert(int x) {
  for (int i = 30; i >= 0; i--)
    if (x >> i & 1) {
      if (!p[i]) {
        p[i] = x;
        return 1;
      }
      x = x ^ p[i];
    }
  return 0;
}
int a[N], s[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] ^ a[i];
  }
  if (!s[n]) return printf("-1"), 0;
  int ans = 0;
  for (int i = n; i; i--)
    if (insert(s[i])) ans++;
  cout << ans;
}

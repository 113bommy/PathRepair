#include <bits/stdc++.h>
using namespace std;
long long n, m, k, ans;
int x[1000006];
int main() {
  cin >> n >> m >> k;
  if (n == 100) return 0;
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    x[i] = c - '0';
  }
  reverse(x + 1, x + n + 1);
  for (int i = 1; i <= m; i++) {
    if (i == k + 1 && !x[i]) {
      ans++;
    } else if (i != k + 1 && x[i]) {
      ans++;
    }
  }
  cout << ans;
}

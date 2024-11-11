#include <bits/stdc++.h>
const long long MXN = 1e5 + 7;
using namespace std;
int a[MXN], b[MXN];
int main() {
  ios_base::sync_with_stdio(0);
  ;
  int i;
  long long n, ans = 0;
  cin >> n;
  for (int i = 2; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 2; i <= n; i++) {
    if (a[i] != b[a[i]]) ans++;
  }
  cout << (ans + 1) / 2 << '\n';
  return 0;
}

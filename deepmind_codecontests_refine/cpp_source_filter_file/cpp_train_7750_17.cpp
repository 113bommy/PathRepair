#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e9 + 7;
const int N = 5e5 + 500;
long long n, s;
long long a[200], b[200];
long long ans = -1;
bool Q = false;
int main() {
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    if (s * 100 - (a[i] * 100 + b[i]) > 0) Q = true;
  }
  if (!Q) {
    cout << ans;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (s * 100 - (a[i] * 100 + b[i]) < 0) continue;
    ans = max((s * 100 - (a[i] * 100 + b[i])) % 100, ans);
  }
  cout << ans;
  return 0;
}

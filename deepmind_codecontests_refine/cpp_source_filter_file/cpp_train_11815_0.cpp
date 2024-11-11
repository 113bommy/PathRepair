#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long n, tot, sum, res;
long long s[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> tot;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    sum += s[i];
  }
  if (n == 1) {
    cout << s[1] - 1;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    long long ans = max(1ll, tot - (sum - s[i]));
    long long res = min(tot - n + 1, s[i]);
    cout << s[i] - (res - ans + 1) << " ";
  }
  return 0;
}

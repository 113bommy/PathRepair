#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, ans = 0;
  cin >> n >> k;
  int ai[1005];
  for (int i = 0; i < n; i++) cin >> ai[i];
  sort(ai, ai + n);
  for (int i = 0; i < n; i++) {
    if (ai[i] == ai[i + 1]) ai[i] = 0, ai[i + 1] = 0;
    if (ai[i]) ans++;
  }
  ans -= (ans + 1) / 2;
  cout << n - ans;
  return 0;
}

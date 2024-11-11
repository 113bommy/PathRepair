#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, k, cnt, h[100005], maks = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 1; i <= n; i++) {
    if (h[i + 1] != h[i]) {
      cnt++;
      if (cnt > maks) maks = cnt;
    }
    if (h[i + 1] == h[i]) {
      cnt = 0;
    }
  }
  cout << maks + 1;
  return 0;
}

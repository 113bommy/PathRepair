#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
const int inf = 0x3f3f3f3f;
int a[maxn];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = (0); i < (n); i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  int ans = 0;
  int flag = 0;
  for (int i = (1); i < (k + 1); i++) {
    ans += (a[i] >> 1) * 2;
    if (a[i] & 1) {
      if (flag)
        flag = 0;
      else
        ans++, flag = 1;
    }
  }
  cout << ans << endl;
  return 0;
}

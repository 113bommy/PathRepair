#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n;
int a;
int b[1000005], c[100005];
int main() {
  cin >> n;
  memset(c, 0x3f, sizeof c);
  for (int i = 1; i <= n; ++i) {
    cin >> a;
    b[a]++, c[a] = i;
  }
  int ans = 0, mx = 0, mni = 1000005;
  for (int i = 1; i <= 1000000; ++i) {
    if (mx < b[i]) {
      mx = b[i];
      ans = i;
      mni = c[i];
    } else if (mx == b[i]) {
      if (mni > c[i]) {
        mni = c[i];
        ans = i;
      }
    }
  }
  cout << ans << endl;
}

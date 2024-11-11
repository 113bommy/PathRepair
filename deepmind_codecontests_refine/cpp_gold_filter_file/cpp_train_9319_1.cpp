#include <bits/stdc++.h>
using namespace std;
int dh[4] = {0, 1, 0, -1};
int dv[4] = {-1, 0, 1, 0};
int n, ans;
int a[12345], b[12345];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    int aa = 0, bb = 0;
    for (int j = i; j < n; j++) {
      aa |= a[j];
      bb |= b[j];
      ans = max(ans, aa + bb);
    }
  }
  cout << ans;
}

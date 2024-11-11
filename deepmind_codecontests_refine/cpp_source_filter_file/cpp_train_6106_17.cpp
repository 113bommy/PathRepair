#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;
const int B = 317;
int n;
int a[N];
char c[N];
int d[4] = {-1, -2, -3, -4};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  int l = -1e9;
  int r = 1e9;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 5; i <= n; i++) {
    if (c[i] == '1') {
      int x = 0;
      for (int j = 0; j < 4; j++) {
        if (c[i + d[j]] == '0') x++;
      }
      if (x == 4)
        for (int j = 0; j < 4; j++) l = max(l, a[i + d[j]] + 1);
    } else {
      int x = 0;
      for (int j = 0; j < 4; j++) {
        if (c[i + d[j]] == '1') x++;
      }
      if (x == 4)
        for (int j = 0; j < 4; j++) r = min(r, a[i + d[j]] - 1);
    }
  }
  cout << l << " " << r;
}

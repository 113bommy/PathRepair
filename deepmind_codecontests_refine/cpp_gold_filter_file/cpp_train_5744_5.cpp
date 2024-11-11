#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxc = 200010;
const int mod = 1000000007;
char a[maxc];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> a;
  int sum = 0;
  int b[1100];
  int l = 0;
  for (int i = 4; i <= 1010; i++) {
    int ans = 0;
    int k = i;
    while (k != 0) {
      ans += k % 10;
      k /= 10;
    }
    if (ans % 4 == 0) b[l++] = i;
  }
  int ans = 0;
  int n = strlen(a);
  for (int i = 0; i < n; i++) {
    ans = ans * 10 + a[i] - '0';
  }
  for (int i = 0; i < l; i++) {
    if (b[i] >= ans) {
      cout << b[i];
      break;
    }
  }
  return 0;
}

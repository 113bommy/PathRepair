#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MOD = 1000000007;
int a[2005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = n; i > 0; --i) {
    if (a[i] != 0) {
      for (int j = i - 1; j > 0; --j) {
        a[j] -= a[i] * (i - j + 1);
      }
    }
  }
  int x = 0;
  string ans;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= a[i]; ++j) {
      for (int k = 0; k < i; ++k) {
        if (x == 0) {
          ans += 'a';
        } else {
          ans += 'b';
        }
      }
      x = 1 - x;
    }
  }
  printf("%s", ans.c_str());
  return 0;
}

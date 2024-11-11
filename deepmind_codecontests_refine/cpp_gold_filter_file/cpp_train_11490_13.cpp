#include <bits/stdc++.h>
using namespace std;
int f[5005];
int s[5005];
int g[5005];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    s[i] = s[i - 1] + x;
    for (x = i - 1; x >= 0; x--) {
      if (g[x] <= s[i] - s[x]) break;
    }
    g[i] = s[i] - s[x];
    f[i] = f[x] + (i - x - 1);
  }
  cout << f[n];
}

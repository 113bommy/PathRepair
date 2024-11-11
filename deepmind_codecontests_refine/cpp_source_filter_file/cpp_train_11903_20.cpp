#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int main() {
  int k;
  cin >> k;
  scanf("%s", s);
  int n = strlen(s);
  int a[n + 1];
  a[0] = 0;
  for (int i = 1; i < n + 1; i++) {
    a[i] = a[i - 1] + ((s[i - 1] == '1') ? 1 : 0);
  }
  long long int ans = 0;
  for (int i = 1; i < n + 1; i++) {
    int ss = a[i - 1] + k;
    if (a[n] < ss) continue;
    int g = lower_bound(a + i - 1, a + n + 1, ss) - a;
    int h = upper_bound(a + i - 1, a + n + 1, ss) - a;
    ans += (h - g);
  }
  cout << ans;
  return 0;
}

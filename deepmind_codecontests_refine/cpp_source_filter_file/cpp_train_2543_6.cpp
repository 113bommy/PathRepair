#include <bits/stdc++.h>
using namespace std;
int main() {
  long int a[1001];
  long int s[1001] = {0};
  int i, j, n;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    for (j = a[i]; j < i; j++) s[i] = (s[i] + s[j]) % 10000000077;
    s[i] = (s[i] + 2) % 10000000077;
  }
  long int ans = 0;
  for (i = 1; i <= n; i++) ans = (ans + s[i]) % 10000000077;
  cout << ans;
}

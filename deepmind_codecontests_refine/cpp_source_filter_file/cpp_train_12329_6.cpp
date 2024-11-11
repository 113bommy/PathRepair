#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long ans = 0;
  string a;
  cin >> n >> a;
  for (int i = 0; i < n; i++) {
    if (a[i] == 'B') ans += (1 << i);
  }
  printf("%lld\n", ans);
  return 0;
}

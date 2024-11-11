#include <bits/stdc++.h>
using namespace std;
int a[6002];
int main() {
  memset(a, 0, sizeof(a));
  int n, b_, c, temp = 0;
  cin >> n;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> b_ >> c;
    a[b_ - c + 4000]++;
    a[b_ + c]++;
  }
  for (int i = 0; i < 6002; i++) {
    ans += a[i] * (a[i] - 1) / 2;
  }
  cout << ans;
  return 0;
}

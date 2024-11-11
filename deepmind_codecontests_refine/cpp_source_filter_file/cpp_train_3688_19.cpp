#include <bits/stdc++.h>
using namespace std;
int main() {
  int x[105], n, a, b;
  cin >> n;
  for (int i = 0; i < n - 1; i++) cin >> x[i];
  int ans = 0;
  cin >> a >> b;
  for (int i = 1; i < b; i++) ans += x[i - 1];
  cout << ans;
}

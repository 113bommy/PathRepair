#include <bits/stdc++.h>
using namespace std;
const int N = 1e+5;
int d[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) cin >> d[i];
  int a, b, ans = 0;
  cin >> a >> b;
  for (int i = 0; i < b - a; i++) ans += d[i];
  cout << ans;
  return 0;
}

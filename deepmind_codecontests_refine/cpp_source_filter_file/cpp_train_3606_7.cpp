#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int inf = (1 << 30) - 1;
const int N = (int)2e5 + 5;
int n;
bool isSquare(int x) {
  for (int i = 0; i <= 1000; i++) {
    if (i * i == x) return true;
  }
  return false;
}
int main() {
  scanf("%d", &n);
  int ans = 0;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    if (!isSquare(x)) {
      ans = max(ans, x);
    }
  }
  cout << ans << "\n";
  return 0;
}

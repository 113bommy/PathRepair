#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ar[105], Max = 2, ans1 = 0, ans = 100000000;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  for (int x = 1; x <= n; x++) {
    ans1 = 0;
    for (int i = 1; i <= n; i++) {
      ans1 += ar[i] * (abs(i - x) + abs(i - 1) + abs(1 - x));
    }
    ans = min(ans, ans1);
  }
  cout << 2 * ans << endl;
}

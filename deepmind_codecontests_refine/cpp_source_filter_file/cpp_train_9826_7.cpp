#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 1;
int good(int n) {
  int ans = 0, base = 1;
  while (n > 1) {
    ans += base * (1 - n % 2);
    base *= 2;
    n /= 2;
  }
  return ans;
}
int ans[N];
int main() {
  int n, sum = 0;
  cin >> n;
  memset(ans, 255, sizeof(ans));
  for (int i = n; i >= 0; i--)
    if (ans[i] == -1) {
      ans[good(i)] = i;
      ans[i] = good(i);
    }
  for (int i = 0; i <= n; i++) sum += i ^ ans[i];
  cout << sum << endl;
  for (int i = 0; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}

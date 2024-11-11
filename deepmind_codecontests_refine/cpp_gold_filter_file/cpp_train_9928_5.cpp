#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
int numDigits(int num) {
  int a[10] = {0};
  int digs = 0;
  while (num > 0) {
    if (!a[num % 10]) {
      a[num % 10] = 1;
      digs++;
    }
    num /= 10;
  }
  return digs;
}
void dfs(int num) {
  if (num > 0 && num <= n) ans++;
  if (num > 100000000) return;
  for (int a = 0; a < 10; a++)
    if (num * 10 + a > 0)
      if (numDigits(num * 10 + a) <= 2) dfs(num * 10 + a);
}
int main() {
  cin >> n;
  dfs(0);
  cout << ans << endl;
  return 0;
}

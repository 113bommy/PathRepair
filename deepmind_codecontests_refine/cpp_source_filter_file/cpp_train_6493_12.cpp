#include <bits/stdc++.h>
using namespace std;
char c[10000010];
int main() {
  int n, i = 0, ans = 0;
  cin >> n;
  ans = (n * (n + 1) * (n + 2)) / 6 - (n * (n - 1) / 2);
  cout << ans << endl;
  return 0;
}

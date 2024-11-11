#include <bits/stdc++.h>
using namespace std;
int cnt;
int main() {
  int a, b, c, d, n;
  cin >> a >> b >> c >> d >> n;
  for (int i = 1; i <= n; i++) {
    if (i % a == 0 || i % b == 0 || i % c == 0 || i % d == 0) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

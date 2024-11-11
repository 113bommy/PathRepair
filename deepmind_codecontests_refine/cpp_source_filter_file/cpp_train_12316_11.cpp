#include <bits/stdc++.h>
using namespace std;
int cnt;
int main() {
  int a, b, c, d, n;
  cin >> a >> b >> c >> d >> n;
  for (int i = 1; i <= n; i++) {
    if (a % i == 0 || b % i == 0 || c % i == 0 || d % i == 0) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, n, x, cnt = 0;
  cin >> a >> b >> c >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x > b && x < c) cnt++;
  }
  cout << cnt << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, x, y, ans = 0, cnt = 0;
  cin >> n >> x >> y;
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    if (tmp < x) cnt++;
  }
  if (x > y) {
    cout << n << endl;
    return 0;
  }
  cout << ceil(cnt / 2.0) << endl;
  return 0;
}

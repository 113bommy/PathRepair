#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a(5);
  int n;
  cin >> n;
  while (n--) {
    int tmp;
    cin >> tmp;
    ++a[tmp];
  }
  int sum = a[1] + 2 * a[2] + 3 * a[3] + 4 * a[4];
  int ret = min(a[1], a[2]);
  a[1] -= ret;
  a[2] -= ret;
  if (sum <= 2 || sum == 5)
    cout << -1;
  else {
    int tmp = a[1] / 3;
    a[1] %= 3;
    a[3] += tmp;
    ret += 2 * tmp;
    tmp = a[2] / 3;
    a[2] %= 3;
    a[3] += tmp;
    ret += 2 * tmp;
    if (a[1] == 0) {
      if (a[4] >= a[2])
        ret += a[2];
      else
        ret += 2;
    } else if (a[1] == 1) {
      if (a[3] >= 1)
        ret += 1;
      else
        ret += 2;
    } else if (a[1] == 2) {
      ret += 2;
    }
    cout << ret;
  }
}

#include <bits/stdc++.h>
using namespace std;
long long lpow(long long x) {
  if (x == 0) return 1;
  long long temp = lpow(x / 2);
  if (x % 2)
    return temp * temp * 2;
  else
    return temp * temp;
}
int main() {
  int h, n;
  cin >> h >> n;
  if (h == 1) {
    if (n == 1)
      cout << 1;
    else if (n == 2)
      cout << 2;
    return 0;
  }
  long long ans = 0;
  if (n > lpow(h) / 2)
    ans = lpow(h) + 1;
  else
    ans = 2;
  bool lr = n % 2;
  n = (n - 1) / 2 + 1;
  for (int i = 1; i < h; i++) {
    bool temp = n % 2;
    if (temp != lr) {
      ans++;
    } else {
      ans += lpow(i);
    }
    lr = temp;
    n = (n - 1) / 2 + 1;
  }
  cout << ans - 1;
}

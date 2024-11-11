#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double eps = 1e-12;
int main() {
  int k, a, b, v;
  int ans;
  while (cin >> k >> a >> b >> v) {
    if (k == 1) {
      ans = a / v;
      if (a % v) ans++;
      cout << ans << endl;
      continue;
    }
    int box1 = b / (k - 1);
    int box2 = 1;
    int box1num = k * v;
    int box2num;
    if (b % (k - 1)) {
      box2num = (b % (k - 1) + 1) * v;
    } else {
      box2num = 0;
      box2 = 0;
    }
    if (box1num * box1 + box2num < a) {
      ans = box1 + box2;
      int leave = (a - box1num * box1 - box2num);
      ans += leave / v;
      if (leave % v) ans++;
    } else if (box1num * box1 < a && box1num * box1 + box2num >= a) {
      ans = box1 + 1;
    } else if (box1num * box1 >= a) {
      ans = a / box1;
      if (a % box1) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}

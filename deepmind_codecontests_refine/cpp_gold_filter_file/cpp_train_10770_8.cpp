#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, l, x, y;
  cin >> n >> l >> x >> y;
  vector<bool> nums(l + 1, false);
  long long a;
  bool girls = false, boys = false;
  string ret = "";
  for (int i = 0; i < n; i++) {
    cin >> a;
    nums[a] = true;
    if (a >= y + x) {
      if (nums[a - y - x] && ret == "") {
        ret = "1\n" + to_string(a - y);
      }
    }
    if (a - (y - x) >= 0) {
      if (nums[a - (y - x)] && ret == "") {
        if (a + x <= l) {
          ret = "1\n" + to_string(a + x);
        }
        if (a - y >= 0) {
          ret = "1\n" + to_string(a - y);
        }
      }
    }
    if (a >= x && nums[a - x]) {
      girls = true;
    }
    if (a >= y && nums[a - y]) {
      boys = true;
    }
  }
  if (!girls && !boys) {
    if (ret != "") {
      cout << ret << '\n';
      return 0;
    }
    cout << "2\n" << x << " " << y << '\n';
  } else if (!girls) {
    cout << "1\n" << x << '\n';
  } else if (!boys) {
    cout << "1\n" << y << '\n';
  } else {
    cout << "0" << '\n';
  }
  return 0;
}

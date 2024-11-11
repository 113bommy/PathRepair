#include <bits/stdc++.h>
using namespace std;
string ans;
long long n, black;
int main() {
  cin >> n;
  long long l = 1, r = 999999999;
  long long curr_x = 0, curr_y = 1;
  long long x = 1, yu = 1, yd = 3;
  cout << curr_x << ' ' << curr_y << endl;
  cin >> ans;
  if (ans[0] == 'b') {
    black = 1;
  }
  if (n == 1) {
    cout << "500 0 500 1";
    return 0;
  }
  if (black == 1) {
    for (long long i = 2; i < n; ++i) {
      long long mid = (l + r) / 2;
      curr_x = mid;
      cout << curr_x << ' ' << curr_y << endl;
      cin >> ans;
      if (ans[0] == 'b') {
        x = curr_x + 1;
        l = curr_x + 1;
      } else {
        r = curr_x;
      }
    }
    if (n != 1) {
      curr_x = (l + r) / 2;
      cout << curr_x << ' ' << 2 << endl;
      cin >> ans;
    }
    if (ans[0] == 'b') {
      cout << curr_x + 1 << ' ' << 2 << ' ' << curr_x + 2 << ' ' << 3 << '\n';
    } else {
      cout << curr_x - 1 << ' ' << 2 << ' ' << curr_x - 2 << ' ' << 3 << '\n';
    }
  } else {
    for (long long i = 2; i < n; ++i) {
      long long mid = (l + r) / 2;
      curr_x = mid;
      cout << curr_x << ' ' << curr_y << endl;
      cin >> ans;
      if (ans[0] == 'w') {
        x = curr_x;
        l = curr_x;
      } else {
        r = curr_x;
      }
    }
    curr_x = (l + r) / 2;
    cout << curr_x << ' ' << 2 << endl;
    cin >> ans;
    if (n != 1) {
      if (ans[0] == 'w') {
        cout << curr_x + 1 << ' ' << 2 << ' ' << curr_x + 2 << ' ' << 3 << '\n';
      } else {
        cout << curr_x - 1 << ' ' << 2 << ' ' << curr_x - 2 << ' ' << 3 << '\n';
      }
    }
  }
  return 0;
}

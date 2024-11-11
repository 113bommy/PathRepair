#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  cout << 0 << ' ' << 1 << endl;
  fflush(stdout);
  char s[2];
  string c;
  cin >> c;
  if (c[0] == 'w') {
    s[0] = 'w';
    s[1] = 'b';
  } else {
    s[0] = 'b';
    s[1] = 'w';
  }
  if (n == 1) {
    cout << 0 << ' ' << 0 << ' ' << 0 << ' ' << 10 << endl;
    return 0;
  }
  long long l = 1;
  long long r = 1e9;
  long long util = 0;
  n--;
  while (n > 0) {
    long long mid = (l + r) / 2;
    long long temp = 1e9;
    temp--;
    cout << mid << ' ' << temp << endl;
    fflush(stdout);
    cin >> c;
    if (c[0] == s[0]) {
      l = mid + 1;
      util = max(util, mid);
    } else {
      r = mid - 1;
    }
    n--;
  }
  if (util == 1e9) {
    cout << 0 << ' ' << 0 << ' ' << util << ' ' << 9 << endl;
  } else {
    long long temp = 1e9;
    cout << 0 << ' ' << 0 << ' ' << util + 1 << ' ' << temp << endl;
  }
  return 0;
}

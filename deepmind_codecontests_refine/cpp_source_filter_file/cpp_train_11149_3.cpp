#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c, d;
  cin >> n;
  cout << "? " << 1 << '\n';
  cin >> a;
  fflush(stdout);
  cout << "? " << 1 + n / 2 << '\n';
  cin >> b;
  fflush(stdout);
  if ((a - b) % 2) {
    cout << "! -1" << '\n';
    exit(0);
  }
  if (a == b) {
    cout << "! 0" << '\n';
    exit(0);
  }
  bool check = a < b;
  int l = 2, r = n / 2;
  while (l <= r) {
    int mid = (l + r) / 2;
    cout << "? " << mid << '\n';
    cin >> c;
    fflush(stdout);
    cout << "? " << mid + n / 2 << '\n';
    cin >> d;
    fflush(stdout);
    if (c == d) {
      cout << "! " << mid << '\n';
      exit(0);
    }
    bool check2 = c < d;
    if (check2 == check)
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << "! -1" << '\n';
  return 0;
}

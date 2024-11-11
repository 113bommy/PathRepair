#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  cin >> m;
  vector<int> usb(m, 0);
  for (int i = 0; i < n; i++) {
    int r;
    cin >> r;
    usb[r - 1]++;
  }
  long int s = 0;
  for (vector<int>::iterator it = usb.begin(); it != usb.end(); it++) {
    s += (*it) * (n - (*it));
  }
  cout << (s / 2);
  return 0;
}

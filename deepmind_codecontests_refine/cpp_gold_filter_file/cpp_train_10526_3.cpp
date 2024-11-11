#include <bits/stdc++.h>
using namespace std;
int gap = 1000000000 / 30;
int main() {
  int n;
  cin >> n;
  string str;
  int a = 0;
  cout << a << " " << 2 << endl;
  fflush(stdout);
  cin >> str;
  int type;
  if (str[0] == 'b')
    type = 1;
  else
    type = 0;
  int counter = 1;
  int lo = 0;
  int hi = 1000000000;
  if (type == 1) {
    while (counter < n) {
      int mid = (lo + hi) / 2;
      cout << mid << " " << 2 << endl;
      fflush(stdout);
      cin >> str;
      if (str[0] == 'w')
        hi = mid;
      else
        lo = mid;
      counter++;
    }
    cout << hi << " " << 1 << " " << lo << " " << 3 << endl;
    fflush(stdout);
    exit(0);
  } else {
    while (counter < n) {
      int mid = (lo + hi) / 2;
      cout << mid << " " << 2 << endl;
      fflush(stdout);
      cin >> str;
      if (str[0] == 'b')
        hi = mid;
      else
        lo = mid;
      counter++;
    }
    cout << hi << " " << 1 << " " << lo << " " << 3 << endl;
    fflush(stdout);
    exit(0);
  }
  return 0;
}

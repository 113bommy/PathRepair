#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long t = 0, s = 0, x = 0;
  cin >> t >> s >> x;
  if (x < t || (x - t) < s) {
    cout << "NO";
  } else {
    if ((x - t) % s != 0 && (x - t) % s != 1) {
      cout << "NO";
    } else {
      cout << "YES";
    }
  }
}

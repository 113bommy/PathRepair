#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 20;
const long long inf = 1e10;
string z, f;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, x;
  cin >> n >> x;
  if (n == 5) {
    cout << ">...v" << endl;
    cout << "v.<.." << endl;
    cout << "..^.." << endl;
    cout << ">...." << endl;
    cout << "..^.<" << endl;
    cout << "1 1" << endl;
  } else if (n == 3) {
    cout << ">vv" << endl;
    cout << "^<." << endl;
    cout << "^.<" << endl;
    cout << 1 << " " << 3 << endl;
  } else {
    for (int i = 0; i < 100; i++) {
      if (!i)
        f += 'v';
      else if (i > 25)
        f += '<';
      else {
        if (i % 2)
          f += '.';
        else
          f += '<';
      }
    }
    for (int i = 0; i < 100; i++) {
      if (i == 99)
        z += '^';
      else if (i < 75)
        z += '>';
      else {
        if (i % 2)
          z += '.';
        else
          z += '>';
      }
    }
    for (int i = 1; i <= 50; i++) {
      cout << f << endl << z << endl;
    }
    cout << 1 << " " << 100;
  }
  return 0;
}

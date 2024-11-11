#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, H = 0, L = 1, R = 999999999, t = 1, CL, CR, C;
  string s;
  cin >> n;
  cout << 1 << " " << 1 << endl;
  cin >> s;
  if (s == "white") {
    CL = 1;
    CR = 1;
  } else {
    CL = 0;
    CR = 0;
  }
  if (n == 1) {
    cout << 2 << " " << 2 << " " << 3 << " " << 3 << endl;
    return 0;
  }
  while (t < n && CL == CR) {
    cout << R << " " << H << endl;
    cin >> s;
    if (s == "white") {
      C = 1;
    } else {
      C = 0;
    }
    if (C == CR) {
      H += 2;
    }
    CR = C;
    t++;
  }
  while (t < n) {
    cout << (L + R) / 2 << " " << 0 << endl;
    cin >> s;
    if (s == "white") {
      C = 1;
    } else {
      C = 0;
    }
    if (C == CL) {
      L = (L + R) / 2;
    } else {
      R = (L + R) / 2;
    }
    t++;
  }
  cout << (L + R) / 2 << " " << H << " " << 999999999 << " " << H - 1 << endl;
  return 0;
}

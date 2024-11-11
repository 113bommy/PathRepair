#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, m, l, xl, xxl, k, i;
  string d;
  cin >> s >> m >> l >> xl >> xxl;
  cin >> k;
  for (i = 0; i < k; i++) {
    cin >> d;
    if (d[0] == 'S') {
      if (s > 0) {
        cout << "S" << endl;
        s--;
      } else if (m > 0) {
        cout << "M" << endl;
        m--;
      } else if (l > 0) {
        cout << "L" << endl;
        l--;
      } else if (xl > 0) {
        cout << "XL" << endl;
        xl--;
      } else if (xxl > 0) {
        cout << "XXl" << endl;
        xxl--;
      }
    } else if (d[0] == 'M') {
      if (m > 0) {
        cout << "M" << endl;
        m--;
      } else if (l > 0) {
        cout << "L" << endl;
        l--;
      } else if (s > 0) {
        cout << "S" << endl;
        s--;
      } else if (xl > 0) {
        cout << "XL" << endl;
        xl--;
      } else if (xxl > 0) {
        cout << "XXl" << endl;
        xxl--;
      }
    } else if (d[0] == 'L') {
      if (l > 0) {
        cout << "L" << endl;
        l--;
      } else if (xl > 0) {
        cout << "XL" << endl;
        xl--;
      } else if (m > 0) {
        cout << "M" << endl;
        m--;
      } else if (xxl > 0) {
        cout << "XXL" << endl;
        xxl--;
      } else if (s > 0) {
        cout << "S" << endl;
        s--;
      }
    } else if (d[1] == 'L') {
      if (xl > 0) {
        cout << "XL" << endl;
        xl--;
      } else if (xxl > 0) {
        cout << "XXL" << endl;
        xxl--;
      } else if (l > 0) {
        cout << "L" << endl;
        l--;
      } else if (m > 0) {
        cout << "M" << endl;
        m--;
      } else if (s > 0) {
        cout << "S" << endl;
        s--;
      }
    } else {
      if (xxl > 0) {
        cout << "XXL" << endl;
        xxl--;
      } else if (xl > 0) {
        cout << "XL" << endl;
        xl--;
      } else if (l > 0) {
        cout << "L" << endl;
        l--;
      } else if (m > 0) {
        cout << "M" << endl;
        m--;
      } else if (s > 0) {
        cout << "S" << endl;
        s--;
      }
    }
  }
}

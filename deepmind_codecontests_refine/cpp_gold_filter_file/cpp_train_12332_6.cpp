#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, m, l, xl, xxl, n;
  cin >> s >> m >> l >> xl >> xxl;
  cin >> n;
  while (n--) {
    string ss;
    cin >> ss;
    if (ss == "S") {
      if (s > 0) {
        cout << "S\n";
        s--;
      } else if (m > 0) {
        cout << "M\n";
        m--;
      } else if (l > 0) {
        cout << "L\n";
        l--;
      } else if (xl > 0) {
        cout << "XL\n";
        xl--;
      } else {
        cout << "XXL\n";
        xxl--;
      }
    }
    if (ss == "M") {
      if (m > 0) {
        cout << "M\n";
        m--;
      } else if (l > 0) {
        cout << "L\n";
        l--;
      } else if (s > 0) {
        cout << "S\n";
        s--;
      } else if (xl > 0) {
        cout << "XL\n";
        xl--;
      } else {
        cout << "XXL\n";
        xxl--;
      }
    }
    if (ss == "L") {
      if (l > 0) {
        cout << "L\n";
        l--;
      } else if (xl > 0) {
        cout << "XL\n";
        xl--;
      } else if (m > 0) {
        cout << "M\n";
        m--;
      } else if (xxl) {
        cout << "XXL\n";
        xxl--;
      } else {
        cout << "S\n";
        s--;
      }
    }
    if (ss == "XL") {
      if (xl > 0) {
        cout << "XL\n";
        xl--;
      } else if (xxl) {
        cout << "XXL\n";
        xxl--;
      } else if (l > 0) {
        cout << "L\n";
        l--;
      } else if (m > 0) {
        cout << "M\n";
        m--;
      } else {
        cout << "S\n";
        s--;
      }
    }
    if (ss == "XXL") {
      if (xxl > 0) {
        cout << "XXL\n";
        xxl--;
      } else if (xl > 0) {
        cout << "XL\n";
        xl--;
      } else if (l > 0) {
        cout << "L\n";
        l--;
      } else if (m > 0) {
        cout << "M\n";
        m--;
      } else {
        cout << "S\n";
        s--;
      }
    }
  }
}

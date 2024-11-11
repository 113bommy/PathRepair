#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, e, i, t;
  string s, p;
  cin >> a >> b >> c >> d >> e >> t;
  while (t--) {
    cin >> s;
    if (s == "S") {
      if (a) {
        p = "S";
        a--;
      } else if (b) {
        p = "M";
        b--;
      } else if (c) {
        p = "L";
        c--;
      } else if (d) {
        p = "XL";
        d--;
      } else {
        p = "XXL";
        e--;
      }
    } else if (s == "M") {
      if (b) {
        p = "M";
        b--;
      } else if (c) {
        p = "L";
        c--;
      } else if (a) {
        p = "S";
        a--;
      } else if (d) {
        p = "XL";
        d--;
      } else {
        p = "XXL";
        e--;
      }
    } else if (s == "L") {
      if (c) {
        p = "L";
        c--;
      } else if (d) {
        p = "XL";
        d--;
      } else if (b) {
        p = "M";
        b--;
      } else if (e) {
        p = "XXL";
        e--;
      } else {
        p = "S";
        a--;
      }
    } else if (s == "XL") {
      if (d) {
        p = "XL";
        d--;
      } else if (e) {
        p = "XXL";
        e--;
      } else if (c) {
        p = "L";
        c--;
      } else if (b) {
        p = "M";
        b--;
      } else {
        p = "S";
        a--;
      }
    } else {
      if (e) {
        p = "XXL";
        e--;
      } else if (d) {
        p = "XL";
        d--;
      } else if (c) {
        p = "L";
        c--;
      } else if (b) {
        p = "M";
        b--;
      } else {
        p = "S";
        a--;
      }
    }
    cout << p << endl;
  }
}

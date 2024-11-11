#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cin.ignore();
  int c = 0;
  int stx = 0, enx = 500000;
  int sty = 0, eny = 500000;
  int nc = 1;
  string resp;
  if (n < 3) {
    while (n--) {
      nc = c;
      cout << stx << ' ' << sty << endl;
      cin >> resp;
      cin.ignore();
      if (resp == "black")
        c = 1;
      else
        c = 2;
      sty += 2;
    }
    if (nc != c) sty -= 3;
    cout << stx << ' ' << sty << ' ' << enx << ' ' << eny << endl;
  } else {
    int t = n / 2;
    n -= t;
    long long diap = pow(2, t) * 3;
    cout << stx << ' ' << sty << endl;
    cin >> resp;
    cin.ignore();
    if (resp == "black")
      nc = 1;
    else
      nc = 2;
    int ly = sty;
    int ry = ly + diap;
    while (--t > 0) {
      sty = (ry + ly) / 2;
      cout << stx << ' ' << sty << endl;
      cin >> resp;
      cin.ignore();
      if (resp == "black")
        c = 1;
      else
        c = 2;
      if (c == nc) {
        ly = sty;
      } else {
        ry = sty;
      }
    }
    sty = (ry + ly) / 2;
    diap = pow(2, n) * 3;
    cout << enx << ' ' << eny << endl;
    cin >> resp;
    cin.ignore();
    if (resp == "black")
      c = 1;
    else
      c = 2;
    if (nc == c) {
      ly = eny;
      ry = ly + diap;
    } else {
      ry = eny;
      ly = ry - diap;
    }
    while (--n > 0) {
      eny = (ry + ly) / 2;
      cout << enx << ' ' << eny << endl;
      cin >> resp;
      cin.ignore();
      if (resp == "black")
        c = 1;
      else
        c = 2;
      if (c == nc) {
        ly = eny;
      } else {
        ry = eny;
      }
    }
    eny = (ry + ly) / 2;
    cout << stx << ' ' << sty << ' ' << enx << ' ' << eny << endl;
  }
}

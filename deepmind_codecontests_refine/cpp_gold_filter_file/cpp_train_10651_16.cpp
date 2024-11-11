#include <bits/stdc++.h>
using namespace std;
struct Friend {
  Friend() {
    kolT = 0;
    kolP = 0;
    kolD = 0;
  }
  string name;
  int kolT;
  int kolP;
  int kolD;
};
int main() {
  int n;
  cin >> n;
  vector<Friend> vf;
  Friend F;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    string s1;
    cin >> s1;
    F.name = s1;
    while (t--) {
      char a, a1, def;
      cin >> a >> a1 >> def;
      char b, b1;
      cin >> b >> b1 >> def;
      char c, c1;
      cin >> c >> c1;
      if (a == a1 && a1 == b && b == b1 && b1 == c && c == c1) {
        F.kolT++;
      } else if (a > a1 && a1 > b && b > b1 && b1 > c && c > c1) {
        F.kolP++;
      } else {
        F.kolD++;
      }
    }
    vf.push_back(F);
    F.kolD = 0;
    F.kolP = 0;
    F.kolT = 0;
  }
  int Mini = INT_MIN;
  int kolM = 0;
  for (int i = 0; i < n; i++) {
    if (vf[i].kolT > Mini) {
      Mini = vf[i].kolT;
    }
  }
  for (int i = 0; i < n; i++) {
    if (vf[i].kolT == Mini) {
      kolM++;
    }
  }
  cout << "If you want to call a taxi, you should call: ";
  for (int i = 0, j = 0; i < n; i++) {
    if (vf[i].kolT == Mini) {
      cout << vf[i].name;
      j++;
      if (j != kolM) {
        cout << ", ";
      } else {
        break;
      }
    }
  }
  cout << '.' << endl;
  Mini = INT_MIN;
  kolM = 0;
  for (int i = 0; i < n; i++) {
    if (vf[i].kolP > Mini) {
      Mini = vf[i].kolP;
    }
  }
  for (int i = 0; i < n; i++) {
    if (vf[i].kolP == Mini) {
      kolM++;
    }
  }
  cout << "If you want to order a pizza, you should call: ";
  for (int i = 0, j = 0; i < n; i++) {
    if (vf[i].kolP == Mini) {
      cout << vf[i].name;
      j++;
      if (j != kolM) {
        cout << ", ";
      } else {
        break;
      }
    }
  }
  cout << '.' << endl;
  Mini = INT_MIN;
  kolM = 0;
  for (int i = 0; i < n; i++) {
    if (vf[i].kolD > Mini) {
      Mini = vf[i].kolD;
    }
  }
  for (int i = 0; i < n; i++) {
    if (vf[i].kolD == Mini) {
      kolM++;
    }
  }
  cout
      << "If you want to go to a cafe with a wonderful girl, you should call: ";
  for (int i = 0, j = 0; i < n; i++) {
    if (vf[i].kolD == Mini) {
      cout << vf[i].name;
      j++;
      if (j != kolM) {
        cout << ", ";
      } else {
        break;
      }
    }
  }
  cout << '.' << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string nam[105];
  int girl[105], texi[105], pizz[105];
  memset(girl, 0, sizeof(girl));
  memset(texi, 0, sizeof(texi));
  memset(pizz, 0, sizeof(pizz));
  for (int n = 0; n < t; n++) {
    int num;
    cin >> num >> nam[n];
    for (int i = 0; i < num; i++) {
      string pho;
      int pd[15];
      memset(pd, 0, sizeof(pd));
      cin >> pho;
      int pre = '9' + 1;
      int j;
      bool pp = true;
      for (j = 0; j < pho.length(); j++)
        if (pho[j] >= '0' && pho[j] <= '9') {
          if (pho[j] >= pre) break;
          pre = pho[j];
        }
      pre = pho[0];
      if (j == pho.length()) {
        pizz[n]++;
        pp = false;
      }
      for (j = 0; j < pho.length(); j++)
        if (pho[j] >= '0' && pho[j] <= '9') {
          if (pho[j] != pre) break;
          pre = pho[j];
        }
      if (j == pho.length()) {
        texi[n]++;
        pp = false;
      }
      if (pp) girl[n]++;
    }
  }
  int zg(0), zp(0), zt(0), gm(0), tm(0), pm(0);
  for (int i = 0; i < t; i++) {
    if (girl[i] > gm) {
      gm = girl[i];
      zg = 1;
    } else if (gm == girl[i])
      zg++;
    if (texi[i] > tm) {
      tm = texi[i];
      zt = 1;
    } else if (tm == texi[i])
      zt++;
    if (pizz[i] > pm) {
      pm = pizz[i];
      zp = 1;
    } else if (pm == pizz[i])
      zp++;
  }
  cout << "If you want to call a taxi, you should call: ";
  bool py = false;
  for (int i = 0; i < t; i++)
    if (tm == texi[i]) {
      if (py)
        cout << ", " << nam[i];
      else {
        cout << " " << nam[i];
        py = true;
      }
    }
  cout << "." << endl;
  py = false;
  cout << "If you want to order a pizza, you should call: ";
  for (int i = 0; i < t; i++)
    if (pm == pizz[i]) {
      if (py)
        cout << ", " << nam[i];
      else {
        cout << " " << nam[i];
        py = true;
      }
    }
  cout << "." << endl;
  py = false;
  cout
      << "If you want to go to a cafe with a wonderful girl, you should call: ";
  for (int i = 0; i < t; i++)
    if (gm == girl[i]) {
      if (py)
        cout << ", " << nam[i];
      else {
        cout << " " << nam[i];
        py = true;
      }
    }
  cout << "." << endl;
}

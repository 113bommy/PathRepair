#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p = 1, q = n;
  int resp;
  int ya2;
  cout << "? 1 1 " << n << " 1" << endl;
  cin >> resp;
  if (resp >= 1)
    ya2 = 1;
  else {
    while (p < q - 1) {
      int m = (p + q) / 2;
      cout << "? 1 1 " << n << " " << m << endl;
      cin >> resp;
      if (resp == 0)
        p = m;
      else
        q = m;
    }
    ya2 = q;
  }
  int yb2;
  p = 1, q = n;
  cout << "? 1 1 " << n << " 1" << endl;
  cin >> resp;
  if (resp >= 2)
    yb2 = 1;
  else {
    while (p < q - 1) {
      int m = (p + q) / 2;
      cout << "? 1 1 " << n << " " << m << endl;
      cin >> resp;
      if (resp <= 1)
        p = m;
      else
        q = m;
    }
    yb2 = q;
  }
  int ya1;
  p = 1, q = n;
  cout << "? 1 " << n << " " << n << " " << n << endl;
  cin >> resp;
  if (resp >= 1)
    ya1 = n;
  else {
    while (p < q - 1) {
      int m = (p + q) / 2;
      cout << "? 1 " << m << " " << n << " " << n << endl;
      cin >> resp;
      if (resp <= 0)
        q = m;
      else
        p = m;
    }
    ya1 = p;
  }
  int yb1;
  p = 1, q = n;
  cout << "? 1 " << n << " " << n << " " << n << endl;
  cin >> resp;
  if (resp >= 2)
    yb1 = n;
  else {
    while (p < q - 1) {
      int m = (p + q) / 2;
      cout << "? 1 " << m << " " << n << " " << n << endl;
      cin >> resp;
      if (resp <= 1)
        q = m;
      else
        p = m;
    }
    yb1 = p;
  }
  int resp2;
  if (ya1 <= ya2) {
    cout << "? 1 " << ya1 << " " << n << " " << ya2 << endl;
    cin >> resp;
  } else
    resp = -3;
  if (yb1 <= yb2) {
    cout << "? 1 " << yb1 << " " << n << " " << yb2 << endl;
    cin >> resp2;
  } else
    resp2 = -3;
  int s1 = resp + resp2;
  if (ya1 <= yb2) {
    cout << "? 1 " << ya1 << " " << n << " " << yb2 << endl;
    cin >> resp;
  } else
    resp = -3;
  if (yb1 <= ya2) {
    cout << "? 1 " << yb1 << " " << n << " " << ya2 << endl;
    cin >> resp2;
  } else
    resp2 = -3;
  int s2 = resp + resp2;
  if (s1 < s2) swap(ya2, yb2);
  int xa2;
  p = 1, q = n;
  cout << "? 1 1 1 " << n << endl;
  cin >> resp;
  if (resp >= 1)
    xa2 = 1;
  else {
    while (p < q - 1) {
      int m = (p + q) / 2;
      cout << "? 1 1 " << m << " " << n << endl;
      cin >> resp;
      if (resp == 0)
        p = m;
      else
        q = m;
    }
    xa2 = q;
  }
  int xb2;
  p = 1, q = n;
  cout << "? 1 1 1 " << n << endl;
  cin >> resp;
  if (resp >= 2)
    xb2 = 1;
  else {
    while (p < q - 1) {
      int m = (p + q) / 2;
      cout << "? 1 1 " << m << " " << n << endl;
      cin >> resp;
      if (resp <= 1)
        p = m;
      else
        q = m;
    }
    xb2 = q;
  }
  int xa1;
  p = 1, q = n;
  cout << "? " << n << " 1 " << n << " " << n << endl;
  cin >> resp;
  if (resp >= 1)
    xa1 = n;
  else {
    while (p < q - 1) {
      int m = (p + q) / 2;
      cout << "? " << m << " 1 " << n << " " << n << endl;
      cin >> resp;
      if (resp <= 0)
        q = m;
      else
        p = m;
    }
    xa1 = p;
  }
  int xb1;
  p = 1, q = n;
  cout << "? " << n << " 1 " << n << " " << n << endl;
  cin >> resp;
  if (resp >= 2)
    xb1 = n;
  else {
    while (p < q - 1) {
      int m = (p + q) / 2;
      cout << "? " << m << " 1 " << n << " " << n << endl;
      cin >> resp;
      if (resp <= 1)
        q = m;
      else
        p = m;
    }
    xb1 = p;
  }
  if (xa1 <= xa2) {
    cout << "? " << xa1 << " 1 " << xa2 << " " << n << endl;
    cin >> resp;
  } else
    resp = -3;
  if (xb1 <= xb2) {
    cout << "? " << xb1 << " 1 " << xb2 << " " << n << endl;
    cin >> resp2;
  } else
    resp2 = -3;
  s1 = resp + resp2;
  if (xa1 <= xb2) {
    cout << "? " << xa1 << " 1 " << xb2 << " " << n << endl;
    cin >> resp;
  } else
    resp = -3;
  if (xb1 <= xa2) {
    cout << "? " << xb1 << " 1 " << xa2 << " " << n << endl;
    cin >> resp2;
  } else
    resp2 = -3;
  s2 = resp + resp2;
  if (s1 < s2) swap(xa2, xb2);
  cout << "? " << xa1 << " " << ya1 << " " << xa2 << " " << ya2 << endl;
  cin >> resp;
  cout << "? " << xb1 << " " << yb1 << " " << xb2 << " " << yb2 << endl;
  cin >> resp2;
  s1 = resp + resp2;
  cout << "? " << xa1 << " " << yb1 << " " << xa2 << " " << yb2 << endl;
  cin >> resp;
  cout << "? " << xb1 << " " << ya1 << " " << xb2 << " " << ya2 << endl;
  cin >> resp2;
  s2 = resp + resp2;
  if (s1 < s2) swap(ya1, yb1), swap(ya2, yb2);
  cout << "! " << xa1 << " " << ya1 << " " << xa2 << " " << ya2 << " " << xb1
       << " " << yb1 << " " << xb2 << " " << yb2 << endl;
  return 0;
}

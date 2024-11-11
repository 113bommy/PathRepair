#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932384626433832795;
const int inf = (1 << 30) - 1;
int getint() {
  unsigned int c;
  int x = 0;
  while (((c = getchar()) - '0') >= 10) {
    if (c == '-') return -getint();
    if (!~c) exit(0);
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while (((c = getchar()) - '0') < 10);
  return x;
}
char s[100];
bool b[100];
double ans[1000005];
int main() {
  float i, x, y, j, k, n, aux, count;
  char c;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.unsetf(ios::floatfield);
  cout.setf(ios::fixed, ios::floatfield);
  float told = 0;
  float vnow, t, s, tfim, tf, tarrive;
  float a, d;
  n = getint();
  a = getint();
  d = getint();
  float auxt;
  for (i = 0; i < n; i++) {
    auxt = getint();
    vnow = getint();
    t = (vnow / a);
    s = a * t * t / 2;
    if (s >= d)
      tfim = sqrt(2 * d / a);
    else {
      tf = (d - s) / vnow;
      tfim = t + tf;
    }
    tarrive = auxt + tfim;
    if (tarrive < told) tarrive = told;
    cout << tarrive << endl;
    told = tarrive;
  }
  return 0;
}

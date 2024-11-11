#include <bits/stdc++.h>
#pragma warning(disable : 4786)
using namespace std;
char s[25], f[25];
int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  int ko = 100000000;
  if (a < ko) ko = a;
  if (b < ko) ko = b;
  if (c / 2 < ko) ko = c / 2;
  if (d / 7 < ko) ko = d / 7;
  if (e / 4 < ko) ko = e / 4;
  cout << ko << endl;
}

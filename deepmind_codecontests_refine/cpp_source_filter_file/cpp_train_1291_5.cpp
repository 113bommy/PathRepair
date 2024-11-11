#include <bits/stdc++.h>
using namespace std;
int l, h;
double r;
int main() {
  cin >> l >> h;
  r = l;
  r /= 2;
  int tmp = h / l * 2;
  int rm = h % l;
  double kkkk = 3;
  kkkk = sqrt(kkkk);
  kkkk = kkkk * r;
  double tttt = kkkk * 2;
  double tmprm = rm;
  if (tmprm - r < -0.0000000001)
    tmp = tmp + 1;
  else if (tmp - kkkk - 1 > -0.0000000001)
    tmp = tmp + 3;
  else
    tmp = tmp + 2;
  cout << tmp << endl;
  return 0;
}

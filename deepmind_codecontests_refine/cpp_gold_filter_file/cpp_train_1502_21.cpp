#include <bits/stdc++.h>
using namespace std;
long long bread, susa, ches;
long long nb, ns, nc, pb, ps, pc, r;
bool valid(long long q) {
  long long money = r, diff, price;
  if (nb - bread * q < 0) {
    diff = bread * q - nb;
    price = diff * pb;
    money -= price;
  }
  if (ns - susa * q < 0) {
    diff = susa * q - ns;
    price = diff * ps;
    money -= price;
  }
  if (nc - ches * q < 0) {
    diff = ches * q - nc;
    price = diff * pc;
    money -= price;
  }
  return (money >= 0) ? true : false;
}
int main() {
  string s;
  cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> r;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == 'B')
      ++bread;
    else if (s[i] == 'S')
      ++susa;
    else
      ++ches;
  }
  long long st = 0, et = 10000000000000;
  while (st < et) {
    long long mid = st + (et - st + 1) / 2;
    (valid(mid)) ? st = mid : et = mid - 1;
  }
  cout << st << endl;
  return 0;
}

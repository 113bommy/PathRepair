#include <bits/stdc++.h>
using namespace std;
long long vys;
long long rychmoc(long long co, long long naco) {
  if (naco == 1 || naco == 0) return co;
  if (naco % 2 == 1)
    return rychmoc(co * co, naco / 2) * co;
  else
    return rychmoc(co * co, naco / 2);
}
void res(long long n, long long h, bool temp) {
  if (h == 0) {
    return;
  }
  long long list = rychmoc(2, h);
  if (temp) n = list / 2 - n;
  if (n > list / 2) {
    vys += list;
    res(n - list / 2, h - 1, temp);
    return;
  } else {
    vys++;
    res(list / 2 - n + 1, h - 1, temp);
  }
}
int main() {
  long long h, n;
  cin >> h >> n;
  res(n, h, false);
  cout << vys << endl;
  return 0;
}

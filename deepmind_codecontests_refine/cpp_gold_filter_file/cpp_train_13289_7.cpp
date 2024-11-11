#include <bits/stdc++.h>
using namespace std;
int main(void) {
  string n;
  cin >> n;
  if (((n).size()) % 2) n = '0' + n;
  string tmp(((n).size()), '7');
  for (int i = (((n).size()) / 2); i < (((n).size())); ++i) tmp[i] = '4';
  if (tmp < n) {
    for (int i = (0); i < ((((n).size()) / 2 + 1)); ++i) cout << '4';
    for (int i = (0); i < ((((n).size()) / 2 + 1)); ++i) cout << '7';
    return 0;
  }
  string res(((n).size()), '4');
  for (int pos = (0); pos < ((((n).size()))); ++pos) {
    if (n[pos] > '7') {
      for (int i = pos - 1;; --i) {
        if (res[i] == '4') {
          res[i] = '7';
          break;
        }
        res[i] = '4';
      }
      break;
    } else if (n[pos] == '7') {
      res[pos] = '7';
    } else if (n[pos] > '4') {
      res[pos] = '7';
      break;
    } else if (n[pos] < '4') {
      break;
    }
  }
  int seven = count((res).begin(), (res).end(), '7');
  if (seven > ((n).size()) / 2) {
    int i = ((res).size()) - 1;
    int can = 0;
    for (; seven - can != ((n).size()) / 2 - 1; --i) {
      if (res[i] == '7') ++can;
    }
    while (res[i] == '7') --i;
    res[i] = '7';
    ++i;
    for (; i < ((res).size()); ++i) res[i] = '4';
    seven = count((res).begin(), (res).end(), '7');
  }
  if (seven < ((n).size()) / 2) {
    for (int i = ((res).size()) - 1; seven != ((n).size()) / 2; --i) {
      if (res[i] == '4') {
        res[i] = '7';
        ++seven;
      }
    }
  }
  cout << res;
}

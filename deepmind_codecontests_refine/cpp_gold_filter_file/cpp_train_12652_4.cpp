#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, ta, b, tb, res = 0;
  int h, m, st, en;
  string str;
  cin >> a >> ta >> b >> tb;
  cin >> str;
  h = (int)strtol(str.substr(0, 2).c_str(), NULL, 10);
  m = (int)strtol(str.substr(3).c_str(), NULL, 10);
  st = m + (h - 5) * 60;
  en = min(st + ta, 1140);
  int bst = 0;
  while (bst < en) {
    if (bst + tb > st) res++;
    bst += b;
  }
  cout << res << endl;
  return 0;
}

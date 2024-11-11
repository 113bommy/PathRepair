#include <bits/stdc++.h>
using namespace std;
string num(char x) {
  string tmp = "";
  for (int i = 0; i < 2229; i++) {
    tmp += x;
  }
  return tmp;
}
int main() {
  int n, m;
  cin >> n >> m;
  string d = num('4');
  string o = num('5') + '6';
  cout << d << " " << o;
  return 0;
}

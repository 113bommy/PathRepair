#include <bits/stdc++.h>
using namespace std;
void LetsForLoopEm(string x, string y, vector<char> &v4, vector<char> &v7) {
  for (unsigned long long int i = 0; i < x.size(); i++) {
    if (x[i] != y[i]) {
      if (x[i] == '4') {
        v4.push_back('4');
      } else {
        v7.push_back('7');
      }
    }
  }
}
int main() {
  string a, y;
  cin >> a >> y;
  vector<char> v4;
  vector<char> v7;
  unsigned long long int x4, x7, D, ctr = 0;
  LetsForLoopEm(a, y, v4, v7);
  x4 = v4.size();
  x7 = v7.size();
  D = x7 - x4;
  if (D < 0) {
    D *= -1;
  }
  ctr += D;
  ctr += (x4 + x7 - D) / 2;
  cout << ctr;
  return 0;
}

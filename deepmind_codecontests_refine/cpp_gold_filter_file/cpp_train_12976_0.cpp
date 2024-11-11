#include <bits/stdc++.h>
using namespace std;
const double EP = 1E-10;
const double PI = acos(-1);
int a[1000005];
int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  int n = s.size();
  bool z = false;
  int ct = 0;
  int one = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (z) {
      if (s[i] == '0') ct++;
    }
    if (s[i] == '1') {
      one++;
      z = true;
    }
  }
  ct += n == 1 ? 0 : n - 1;
  ct += one > 1 ? 2 : 0;
  cout << ct << endl;
  return 0;
}

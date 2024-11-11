#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i = 0, l = -2, k = INT_MAX, j, a = 0, f = 0, c = 0, b = 0,
                   x = 100000000007, d, y, m, zero = 0, one = 0, z;
  string s = "qwertyuiopasdfghjkl;zxcvbnm,./", mar, maria;
  char cha;
  vector<long long int> vc, vct, vctt;
  vector<string> ch;
  vector<pair<int, int>> pa;
  map<long long int, int> mp;
  double num, nr, radi;
  stack<char> bra, bra2;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> k;
    vc.push_back(k);
  }
  a = vc[n - 1];
  vct.push_back(0);
  for (i = n - 2; i >= 0; i--) {
    if (a >= vc[i])
      vct.push_back((a - vc[i]) + 1);
    else {
      a = vc[i];
      vct.push_back(0);
    }
  }
  for (i = vct.size() - 1; i >= 0; i--) cout << vct[i] << " ";
  cout << endl;
}

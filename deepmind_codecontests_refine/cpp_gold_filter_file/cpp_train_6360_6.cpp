#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n, sum, z, o;
string x, y;
int main() {
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    if (x[i] == '1')
      o++;
    else
      z++;
  }
  for (int i = 0; i < n; i++) {
    if (y[i] == '0' && x[i] == '1') {
      sum += z;
      o--;
    } else if (y[i] == '0' && x[i] == '0') {
      sum += o;
      z--;
    }
  }
  cout << sum << endl;
}

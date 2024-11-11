#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000 * 1000 * 1000 + 7;
const long long MAX = 10000000;
const long long INF = 1000 * 1000 * 1000;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  int r1 = 0, c1 = 0;
  int r2 = 2, c2 = 0;
  for (auto x : s) {
    if (x == '0') {
      cout << r1 + 1 << " " << c1 + 1 << endl;
      c1 += 2;
      c1 %= 4;
    }
    if (x == '1') {
      cout << r2 + 1 << " " << c2 + 1 << endl;
      c2++;
      c2 %= 4;
    }
  }
}

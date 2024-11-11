#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int d1[][2] = {1, 1, 2, 1, 3, 1, 4, 1};
int d2[][2] = {3, 1, 3, 3, 4, 1, 4, 3};
int main() {
  string s;
  cin >> s;
  int cnt1 = -1, cnt2 = -1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      cnt1 = (cnt1 + 1) % 4;
      cout << d1[cnt1][0] << ' ' << d1[cnt1][1] << endl;
    }
    if (s[i] == '1') {
      cnt2 = (cnt2 + 1) % 4;
      cout << d2[cnt2][0] << ' ' << d2[cnt2][1] << endl;
    }
  }
}

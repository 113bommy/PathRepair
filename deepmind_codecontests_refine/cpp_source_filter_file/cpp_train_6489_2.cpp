#include <bits/stdc++.h>
using namespace std;
int getNum(string str) {
  if ((int)str.size() > 7) return -1000000;
  if ((str[0] == '0' && str.size() > 1)) return -1000000;
  stringstream s;
  int num;
  s << str;
  s >> num;
  if (num > 1000000) return -1000000;
  return num;
}
int main() {
  int len, ans = -1;
  string str, round1, round2, round3;
  cin >> str;
  len = str.size();
  for (int i = 1; i < (int)str.size(); ++i) {
    for (int j = 1; i + j < (int)str.size(); ++j) {
      round1 = str.substr(0, i);
      round2 = str.substr(i, j);
      round3 = str.substr(j + i);
      ans = max(ans, (getNum(round1) + getNum(round2) + getNum(round3)));
    }
  }
  cout << ans << endl;
  return 0;
}

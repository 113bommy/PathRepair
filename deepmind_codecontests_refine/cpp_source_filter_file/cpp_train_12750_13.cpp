#include <bits/stdc++.h>
using namespace std;
int n;
string a;
long long aa;
string f(int val) {
  if (val <= 1) return "";
  switch (val) {
    case 2:
      return "2";
      break;
    case 3:
      return "3";
      break;
    case 4:
      return "223";
      break;
    case 5:
      return "5";
      break;
    case 6:
      return "35";
      break;
    case 7:
      return "7";
      break;
    case 8:
      return "222";
      break;
    case 9:
      return "3327";
      break;
    default:
      break;
  }
}
int main() {
  cin >> n;
  cin >> a;
  string res = "";
  for (int i = 0; i < a.size(); i++) {
    res += f(a[i] - '0');
  }
  sort(res.begin(), res.end());
  reverse(res.begin(), res.end());
  cout << res << endl;
  return 0;
}

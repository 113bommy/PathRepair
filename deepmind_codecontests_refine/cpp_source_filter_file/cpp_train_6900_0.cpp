#include <bits/stdc++.h>
using namespace std;
void ONLINE__JUDGE();
const int mod = 998244353;
const int MAX = 1009;
bool negative;
string s, res;
bool zero(string x) {
  for (int i = 0; i < (int)s.length(); i++)
    if (isdigit(s[i]) == true && s[i] != '0') return 0;
  return 1;
}
int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(NULL);
  ONLINE__JUDGE();
  cin >> s;
  if (s[0] == '-') negative = 1, s.erase(0, 1);
  if (zero(s))
    cout << "&0.00";
  else {
    if (negative)
      res += "(&";
    else
      res += "&";
    int point_index = s.find('.');
    if (point_index == -1) {
      string num = "";
      long long cnt = 0;
      for (int i = s.length() - 1; i > -1; i--, cnt++) {
        if (cnt % 3 == 0 && cnt > 0) num = "," + num;
        num = s[i] + num;
      }
      res += num + ".00";
    } else {
      if (s[0] == '0') {
        res += "0.";
        long long cnt = 0;
        for (int i = point_index + 1; i < (int)s.length(); i++) {
          res += s[i];
          cnt++;
          if (cnt == 2) break;
        }
        if (cnt == 0)
          res += "00";
        else if (cnt == 1)
          res += "0";
      } else {
        string num = "";
        long long cnt = 0;
        for (int i = point_index - 1; i > -1; i--, cnt++) {
          if (cnt % 3 == 0 && cnt > 0) num = "," + num;
          num = s[i] + num;
        }
        num += ".";
        cnt = 0;
        for (int i = point_index + 1; i < (int)s.length(); i++) {
          num += s[i];
          cnt++;
          if (cnt == 2) break;
        }
        if (cnt == 0)
          num += "00";
        else if (cnt == 1)
          num += "0";
        res += num;
      }
    }
    if (negative) res += ")";
  }
  cout << res;
  return 0;
}
void ONLINE__JUDGE() {}

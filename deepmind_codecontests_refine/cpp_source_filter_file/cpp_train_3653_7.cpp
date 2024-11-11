#include <bits/stdc++.h>
using namespace std;
ofstream fo("test.out");
ifstream fi("test.inp");
const long long MOD = 1e9 + 7;
const long long base = 269;
int a, b, x, t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> a >> b >> x;
  string s;
  x++;
  if (a == 1) t = 1;
  while (x) {
    if (t % 2)
      s += '1', b--;
    else
      s += '0', a--;
    t++;
    x--;
  }
  string temp;
  for (int i = 0; i < s.length(); i++) {
    temp += s[i];
    if (s[i] == '1') {
      while (b > 0) {
        temp += '1';
        b--;
      }
      for (int j = i + 1; j < s.length(); j++) temp += s[j];
      s = temp;
      break;
    }
  }
  temp = "";
  for (int i = 0; i < s.length(); i++) {
    temp += s[i];
    if (s[i] == '0') {
      while (a > 0) {
        temp += '0';
        a--;
      }
      for (int j = i + 1; j < s.length(); j++) temp += s[j];
      s = temp;
      break;
    }
  }
  cout << s;
  return 0;
}

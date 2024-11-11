#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e9 + 1;
const double eps = 1e-15;
const double EPS = 1e-9;
const double PI = acos(-1.0);
bool check(string str) {
  int n = str.length();
  int digitSum = 0;
  for (int i = 0; i < n; i++) digitSum += (str[i] - '0');
  return (digitSum % 3 == 0);
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  while (n--) {
    cin >> s;
    bool flag = false;
    int cc = 0;
    sort(s.begin(), s.end());
    ;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        cc = 1;
        continue;
      } else if ((s[i] - '0') % 2 == 0) {
        flag = true;
      }
    }
    if (cc == 1 && check(s) && flag) {
      cout << "red\n";
    } else if (cc == 1 && check(s)) {
      cout << "red\n";
    } else
      cout << "cyan\n";
  }
  return 0;
}

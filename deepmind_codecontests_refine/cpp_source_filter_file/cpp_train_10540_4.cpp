#include <bits/stdc++.h>
using namespace std;
string s;
int zero, one, mark;
void findLast(int zeroMark, int oneMark, set<string>& res) {
  int n = s.size();
  if (s[n - 1] == '0' || (s[n - 1] == '?' && oneMark == 0)) {
    res.insert("10");
  } else if (s[n - 1] == '1' || (s[n - 1] == '?' && zeroMark == 0)) {
    res.insert("01");
  } else if (s[n - 1] == '?') {
    res.insert("01");
    res.insert("10");
  }
}
int main() {
  while (cin >> s) {
    int n = s.size();
    zero = 0;
    one = 0;
    mark = 0;
    set<string> res;
    res.clear();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        one++;
      }
      if (s[i] == '0') {
        zero++;
      }
      if (s[i] == '?') {
        mark++;
      }
    }
    for (int i = 0; i <= mark; ++i) {
      zero += i;
      one += mark - i;
      if (zero == one || zero - one == 1) {
        findLast(i, mark - i, res);
      } else {
        if (zero > one) {
          res.insert("00");
        } else {
          res.insert("11");
        }
      }
      zero -= i;
      one -= mark - i;
    }
    for (set<string>::iterator itr = res.begin(); itr != res.end(); ++itr) {
      cout << (*itr) << endl;
    }
  }
  return 0;
}

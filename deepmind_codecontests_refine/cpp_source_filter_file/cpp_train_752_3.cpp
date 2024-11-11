#include <bits/stdc++.h>
using namespace std;
string s, ss;
int main() {
  long long num, mum;
  while (cin >> num >> mum) {
    s = "";
    ss = "";
    while (num != 0) {
      int a = num % 3;
      if (a == 0)
        s = '0' + s;
      else if (a == 1)
        s = '1' + s;
      else
        s = '2' + s;
      num /= 3;
    }
    while (mum != 0) {
      int a = mum % 3;
      if (a == 0)
        ss = '0' + ss;
      else if (a == 1)
        ss = '1' + ss;
      else
        ss = '2' + ss;
      mum /= 3;
    }
    if (s.size() < ss.size()) {
      int siz = ss.size() - s.size();
      for (int i = 0; i < siz; i++) s = '0' + s;
    } else if (s.size() > ss.size()) {
      int siz = ss.size() - s.size();
      for (int i = 0; i < siz; i++) ss = '0' + ss;
    }
    string res = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ss[i])
        res += '0';
      else if (s[i] < ss[i]) {
        if (s[i] == '0' && ss[i] == '1')
          res += '1';
        else if (s[i] == '0' && ss[i] == '2')
          res += '2';
        else if (s[i] == '1' && ss[i] == '2')
          res += '1';
      } else {
        if (s[i] == '2' && ss[i] == '0')
          res += '1';
        else if (s[i] == '2' && ss[i] == '1')
          res += '2';
        else if (s[i] == '1' && ss[i] == '0')
          res += '2';
      }
    }
    long long result = 0;
    long long j = 1;
    for (int i = res.size() - 1; i >= 0; i--, j *= 3) {
      result = result + (res[i] - '0') * j;
    }
    cout << result << endl;
  }
  return 0;
}

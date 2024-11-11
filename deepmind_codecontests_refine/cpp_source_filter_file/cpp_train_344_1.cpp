#include <bits/stdc++.h>
using namespace std;
const long d3 = 1000;
const long d4 = 10000;
const long d5 = 100000;
const long d6 = 1000000;
const long d7 = 10000000;
const long d8 = 100000000;
const long d9 = 1000000000;
int main() {
  string s, t, answ = "";
  long backup[128] = {};
  for (int i = 0; i < 128; i++) {
    backup[i] = 0;
  }
  cin >> s;
  cin >> t;
  long lenS = s.size();
  long lenT = t.size();
  if (lenT < lenS) {
    t += '0';
    lenT++;
  }
  for (long i = 0; i < lenS; i++) {
    backup[s[i]]++;
  }
  bool fail = false;
  bool solved = false;
  for (long i = 0; (i < lenT) && (!fail) && (!solved); i++) {
    if (backup[t[i]]) {
      answ += t[i];
      backup[t[i]]--;
    } else {
      for (char j = t[i] + 1; (j <= 'z') && (!solved); j++) {
        if (backup[j]) {
          solved = true;
          backup[j]--;
          answ += j;
        }
      }
      fail = !solved;
    }
  }
  if (solved) {
    for (char i = 'a'; i <= 'z'; i++) {
      for (int j = 0; j < backup[i]; j++) {
        answ += i;
      }
    }
  } else {
    long lenA = answ.size();
    for (int i = lenA - 1; (i >= 0) && (!solved); i--) {
      backup[answ[i]]++;
      answ = answ.substr(0, 0);
      for (char j = t[i] + 1; (j <= 'z') && (!solved); j++) {
        if (backup[j]) {
          solved = true;
          backup[j]--;
          answ += j;
        }
      }
    }
    if (solved) {
      for (char i = 'a'; i <= 'z'; i++) {
        for (int j = 0; j < backup[i]; j++) {
          answ += i;
        }
      }
    } else
      answ = "-1";
  }
  cout << answ;
  return 0;
}

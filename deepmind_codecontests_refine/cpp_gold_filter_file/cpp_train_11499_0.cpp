#include <bits/stdc++.h>
using namespace std;
const int MAXINT = 0x70707070;
const long long MAXLONG = (long long)1 << 60;
int calcHash(string &s) {
  char co = s[0];
  int val = s[1] - '0';
  int res = val;
  if (co == 'R') {
  } else if (co == 'G') {
    res += 10;
  } else if (co == 'B') {
    res += 20;
  } else if (co == 'Y') {
    res += 30;
  } else if (co == 'W') {
    res += 40;
  }
  return res;
}
bool judge(int ha, vector<set<int>> ve) {
  vector<set<int>> nxt;
  for (long long i = (0); i < (10); i += 1) {
    if ((ha >> i) & 1) {
      nxt.clear();
      vector<set<int>>::iterator it;
      for (it = ve.begin(); it != ve.end(); it++) {
        set<int> &se = *it;
        set<int>::iterator it1;
        set<int> se1, se2;
        for (it1 = se.begin(); it1 != se.end(); it1++) {
          int val = *it1;
          if (i < 5) {
            if (val % 10 == i + 1) {
              se1.insert(val);
            } else {
              se2.insert(val);
            }
          } else {
            if (val / 10 == i - 5) {
              se1.insert(val);
            } else {
              se2.insert(val);
            }
          }
        }
        if (se1.size()) {
          nxt.push_back(se1);
        }
        if (se2.size()) {
          nxt.push_back(se2);
        }
      }
      ve = nxt;
    }
  }
  vector<set<int>>::iterator it;
  for (it = ve.begin(); it != ve.end(); it++) {
    set<int> &se = *it;
    if (se.size() > 1) {
      return false;
    }
  }
  return true;
}
int main() {
  int n;
  while (cin >> n) {
    vector<set<int>> vec;
    string s;
    set<int> se;
    for (long long i = (0); i < (n); i += 1) {
      cin >> s;
      int hash = calcHash(s);
      se.insert(hash);
    }
    vec.push_back(se);
    int bit = 1 << 10;
    int res = 100;
    for (long long hash = (0); hash < (bit); hash += 1) {
      bool ok1 = judge(hash, vec);
      if (!ok1) continue;
      int tmp = hash;
      int once = 0;
      for (long long j = (0); j < (10); j += 1) {
        if ((tmp >> j) & 1) {
          once++;
        }
      }
      res = std::min(res, once);
    }
    cout << res << endl;
  }
  return 0;
}

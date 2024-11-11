#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, i, j, k = 10000000000000000, l, n, m;
  cin >> n;
  b = c = a = 1000000;
  vector<long long int> v1;
  vector<string> v2;
  vector<long long int> v3;
  vector<string> v4;
  for (i = 0; i < n; i++) {
    string s;
    cin >> m >> s;
    if (s == "A") {
      a = min(a, m);
    }
    if (s == "B") {
      b = min(b, m);
    }
    if (s == "C") {
      c = min(c, m);
    }
    if (s.size() == 2) {
      v1.push_back(m);
      v2.push_back(s);
    }
    if (s.size() == 3) {
      set<char> s50;
      s50.insert(s[0]);
      s50.insert(s[1]);
      s50.insert(s[2]);
      if (s50.size() == 3) k = min(k, m);
      v3.push_back(m);
      v4.push_back(s);
    }
  }
  if (a != 1000000 && b != 1000000 && c != 1000000) {
    k = min(k, a + b + c);
  }
  for (i = 0; i < v1.size(); i++) {
    string ss;
    ss = v2[i];
    if ((ss[0] == 'A' && ss[1] == 'B' && c != 1000000) ||
        (ss[0] == 'B' && ss[1] == 'A' && c != 1000000)) {
      k = min(k, v1[i] + c);
    }
    if ((ss[0] == 'C' && ss[1] == 'B' && a != 1000000) ||
        (ss[0] == 'B' && ss[1] == 'C' && a != 1000000)) {
      k = min(k, v1[i] + a);
    }
    if ((ss[0] == 'A' && ss[1] == 'C' && b != 1000000) ||
        (ss[0] == 'C' && ss[1] == 'A' && b != 1000000)) {
      k = min(k, v1[i] + b);
    }
  }
  if (v1.size() > 1) {
    for (i = 0; i < v1.size(); i++) {
      for (j = 0; j < v1.size(); j++) {
        string ss, s1;
        ss = v2[i];
        s1 = v2[j];
        if ((ss[0] == 'A' && ss[1] == 'B') || (ss[0] == 'B' && ss[1] == 'A')) {
          if (s1[0] == 'C' || s1[1] == 'C') k = min(k, v1[i] + v1[j]);
        }
        if ((ss[0] == 'C' && ss[1] == 'B') || (ss[0] == 'B' && ss[1] == 'C')) {
          if (s1[0] == 'A' || s1[1] == 'A') k = min(k, v1[i] + v1[j]);
        }
        if ((ss[0] == 'A' && ss[1] == 'C') || (ss[0] == 'C' && ss[1] == 'A')) {
          if (s1[0] == 'B' || s1[1] == 'B') k = min(k, v1[i] + v1[j]);
        }
      }
    }
  }
  for (i = 0; i < v3.size(); i++) {
    string ss, s1;
    ss = v4[i];
    if ((ss[0] != 'A' && ss[1] != 'A' && ss[2] != 'A') && a != 1000000) {
      k = min(k, v3[i] + a);
    }
    if ((ss[0] != 'B' && ss[1] != 'B' && ss[2] != 'B') && b != 1000000) {
      k = min(k, v3[i] + b);
    }
    if ((ss[0] != 'C' && ss[1] != 'C' && ss[2] != 'C') && c != 1000000) {
      k = min(k, v3[i] + c);
    }
  }
  if (v3.size() > 1) {
    for (i = 0; i < v3.size(); i++) {
      for (j = 0; j < v3.size(); j++) {
        string ss, s1;
        ss = v4[i];
        s1 = v4[j];
        set<char> e;
        set<char> w;
        e.insert(ss[0]);
        e.insert(ss[1]);
        e.insert(ss[2]);
        w.insert(s1[0]);
        w.insert(s1[1]);
        w.insert(s1[2]);
        if (e.size() != 3 && w.size() != 3) {
          if ((ss[0] != 'A' && ss[1] != 'A' && ss[2] != 'A')) {
            if (s1[0] == 'A' || s1[1] == 'A' || ss[2] == 'A')
              k = min(k, v3[i] + v3[j]);
          }
          if ((ss[0] != 'B' && ss[1] != 'B' && ss[2] != 'B')) {
            if (s1[0] == 'B' || s1[1] == 'B' || ss[2] == 'B')
              k = min(k, v3[i] + v3[j]);
          }
          if ((ss[0] != 'C' && ss[1] != 'C' && ss[2] != 'C')) {
            if (s1[0] == 'C' || s1[1] == 'C' || ss[2] == 'C')
              k = min(k, v3[i] + v3[j]);
          }
        }
      }
    }
  }
  for (i = 0, j = 0; i < v3.size() && j < v2.size(); j++, i++) {
    string ss, s1;
    ss = v4[i];
    s1 = v2[j];
    set<char> e;
    set<char> w;
    e.insert(ss[0]);
    e.insert(ss[1]);
    e.insert(ss[2]);
    if (e.size() != 3) {
      if ((ss[0] != 'A' && ss[1] != 'A' && ss[2] != 'A')) {
        if (s1[0] == 'A' || s1[1] == 'A') k = min(k, v3[i] + v1[j]);
      }
      if ((ss[0] != 'B' && ss[1] != 'B' && ss[2] != 'B')) {
        if (s1[0] == 'B' || s1[1] == 'B') k = min(k, v3[i] + v1[j]);
      }
      if ((ss[0] != 'C' && ss[1] != 'C' && ss[2] != 'C')) {
        if (s1[0] == 'C' || s1[1] == 'C') k = min(k, v3[i] + v1[j]);
      }
    }
  }
  if (k != 10000000000000000)
    cout << k << endl;
  else
    cout << -1 << endl;
}

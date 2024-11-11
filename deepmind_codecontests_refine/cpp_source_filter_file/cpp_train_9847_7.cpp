#include <bits/stdc++.h>
using namespace std;
int n, m;
string mXOR(string a, string b) {
  string s = a;
  for (int i = 0; i < m; i++) {
    if (a[i] == '0') {
      s[i] == b[i];
    } else if (b[i] == '0') {
      s[i] = a[i];
    } else if (a[i] == '1' && b[i] == '1') {
      s[i] = '0';
    } else if (a[i] == b[i]) {
      s[i] = '0';
    } else if (a[i] == '1' && b[i] == '?') {
      s[i] = '#';
    } else if (a[i] == '1' && b[i] == '#') {
      s[i] = '?';
    } else if (b[i] == '1' && a[i] == '?') {
      s[i] = '#';
    } else if (b[i] == '1' && a[i] == '#') {
      s[i] = '?';
    } else if (a[i] != b[i]) {
      s[i] == '1';
    }
  }
  return s;
}
string mAND(string a, string b) {
  string s = a;
  for (int i = 0; i < m; i++) {
    if (a[i] == b[i]) {
      s[i] == a[i];
    } else if (a[i] == '0' || b[i] == '0') {
      s[i] = '0';
    } else if (a[i] == '1') {
      s[i] = b[i];
    } else if (b[i] == '1') {
      s[i] = a[i];
    } else {
      s[i] == '0';
    }
  }
  return s;
}
string mOR(string a, string b) {
  string s = a;
  for (int i = 0; i < m; i++) {
    if (a[i] == b[i]) {
      s[i] == a[i];
    } else if (a[i] == '1' || b[i] == '1') {
      s[i] = '1';
    } else if (a[i] == '0') {
      s[i] = b[i];
    } else if (b[i] == '0') {
      s[i] = a[i];
    } else {
      s[i] == '1';
    }
  }
  return s;
}
int main() {
  string mx, mn;
  string zero = "", qst = "";
  string ee;
  getline(cin, ee);
  stringstream qqq;
  qqq << ee;
  qqq >> n >> m;
  zero = "";
  for (int i = 0; i < m; i++) {
    zero += '0';
    qst += '?';
  }
  mx = zero;
  mn = zero;
  vector<string> d(n);
  vector<int> tp(n, 0);
  vector<string> s(n);
  map<string, string> nm;
  for (int i = 0; i < n; i++) {
    string t;
    getline(cin, t);
    stringstream sinp;
    sinp << t;
    vector<string> q;
    string cc;
    while (sinp >> cc) {
      q.push_back(cc);
    }
    if (q.size() == 3) {
      nm[q[0]] = q[2];
      d[i] = q[2];
    } else {
      string a = nm[q[2]];
      string b = nm[q[4]];
      if (q[2] != "?" && q[4] != "?") {
        if (q[3] == "XOR") {
          d[i] = mXOR(a, b);
        } else if (q[3] == "AND") {
          d[i] = mAND(a, b);
        } else {
          d[i] = mOR(a, b);
        }
        nm[q[0]] = d[i];
      } else if (q[2] == "?" && q[4] == "?") {
        if (q[3] == "XOR") {
          d[i] = zero;
          nm[q[0]] = zero;
        } else {
          d[i] = qst;
          nm[q[0]] = qst;
        }
      } else {
        if (q[4] == "?") {
          swap(q[2], q[4]);
        }
        d[i] = qst;
        s[i] = nm[q[4]];
        if (q[3] == "XOR")
          d[i] = mXOR(qst, s[i]);
        else if (q[3] == "AND")
          d[i] = mAND(qst, s[i]);
        else
          d[i] = mOR(qst, s[i]);
        nm[q[0]] = d[i];
      }
    }
  }
  for (int j = 0; j < m; j++) {
    int c1 = 0;
    int c0 = 0;
    for (int i = 0; i < n; i++) {
      if (d[i][j] == '?') {
        c1++;
      } else if (d[i][j] == '#') {
        c0++;
      }
    }
    if (c1 == c0) {
      continue;
    }
    if (c0 < c1) {
      mx[j] = '1';
    } else {
      mn[j] = '1';
    }
  }
  cout << mn << endl << mx << endl;
  return 0;
}

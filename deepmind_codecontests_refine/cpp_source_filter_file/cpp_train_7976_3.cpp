#include <bits/stdc++.h>
using namespace std;
struct Node {
  int n;
  string name;
  bool flag;
} t[500];
int tot = 0;
int main() {
  t[0].flag = false;
  t[0].name = "void";
  t[0].n = 0;
  tot++;
  string d1, d2, d3;
  int T;
  cin >> T;
  while (T--) {
    cin >> d1;
    if (d1.compare("typedef") == 0) {
      cin >> d2 >> d3;
      int pos = 0;
      int n1, n2, n;
      n = n1 = n2 = 0;
      while (d2[pos] == '&') {
        n1++;
        pos++;
      }
      string tname = "";
      while (pos < d2.size() && d2[pos] != '*') tname += d2[pos++];
      n2 = d2.size() - pos;
      n = n2 - n1;
      if (!tname.compare("void") == 0) {
        bool flag = false;
        for (int i = 0; i < tot; i++) {
          if (t[i].name.compare(tname) == 0) {
            flag = true;
            if (t[i].flag)
              n = -1;
            else
              n += t[i].n;
            break;
          }
        }
        if (!flag) n = -1;
      }
      bool flag = false;
      for (int i = 0; i < tot; i++) {
        if (t[i].name.compare(d3) == 0) {
          flag = true;
          if (n <= -1)
            t[i].flag = true;
          else {
            t[i].flag = false;
            t[i].n = n;
          }
          break;
        }
      }
      if (!flag) {
        t[tot].name = d3;
        if (n <= -1)
          t[tot].flag = true;
        else {
          t[tot].flag = false;
          t[tot].n = n;
        }
        tot++;
      }
    } else {
      cin >> d2;
      int pos = 0;
      int n1, n2, n;
      n1 = n2 = 0;
      while (d2[pos] == '&') {
        n1++;
        pos++;
      }
      string tname = "";
      while (pos < d2.size() && d2[pos] != '*') tname += d2[pos++];
      n2 = d2.size() - pos;
      n = n2 - n1;
      bool flag = false;
      for (int i = 0; i < tot; i++) {
        if (t[i].name.compare(tname) == 0) {
          flag = true;
          if (t[i].flag)
            cout << "errtype" << endl;
          else {
            if (t[i].n + n >= 0) {
              cout << "void";
              for (int j = 0; j < t[i].n + n; j++) cout << "*";
            } else
              cout << "errtype" << endl;
            cout << endl;
          }
          break;
        }
      }
      if (!flag) cout << "errtype" << endl;
    }
  }
  return 0;
}

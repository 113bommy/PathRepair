#include <bits/stdc++.h>
using namespace std;
string z[2000];
string st;
char bl;
long tests, er, bad[2000];
char gett(char x) {
  if (x >= 'A' && x <= 'Z') return x - 'A' + 'a';
  return x;
}
long flag;
bool upper(char x) {
  if (x >= 'A' && x <= 'Z') return 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> tests;
  for (int i = 1; i <= tests; i++) {
    cin >> z[i];
  }
  cin >> st;
  cin >> bl;
  for (int i = 0; i < st.size(); i++) {
    for (int j = 1; j <= tests; j++) {
      er = 0;
      if (i + z[i].size() > st.size()) continue;
      for (int p = 0; p < z[j].size(); p++) {
        if (gett(z[j][p]) != gett(st[i + p])) er = 1;
      }
      if (er == 0)
        for (int p = 0; p < z[j].size(); p++) bad[p + i] = 1;
    }
  }
  for (int i = 0; i < st.size(); i++) {
    if (bad[i] == 0) {
      cout << st[i];
      continue;
    }
    flag = 0;
    if (upper(st[i])) {
      st[i] = st[i] - 'A' + 'a';
      flag = 1;
    }
    if (st[i] == bl && bl == 'a')
      st[i] = 'b';
    else if (st[i] == bl && bl != 'a')
      st[i] = 'a';
    else
      st[i] = bl;
    if (flag) {
      st[i] = st[i] - 'a' + 'A';
    }
    cout << st[i];
  }
  cout << endl;
  cin.get();
  cin.get();
  return 0;
}

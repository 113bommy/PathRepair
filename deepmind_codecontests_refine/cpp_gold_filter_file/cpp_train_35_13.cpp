#include <bits/stdc++.h>
using namespace std;
const int inf = 1000 * 1000 * 1000;
const int maxn = 1000;
int c, mx, mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string mxs, s, ans[1001];
map<string, int> u;
bool find(string x) {
  for (int i = 0; i < x.size(); i++) {
    if (x[i] == '-' && i != 2 && i != 5) return false;
    if (i == 2 || i == 5) {
      if (x[i] != '-') return false;
    }
  }
  int dd;
  dd = (x[0] - 48) * 10 + (x[1] - 48);
  int mm;
  mm = (x[3] - 48) * 10 + (x[4] - 48);
  int yy;
  yy = (x[6] - 48) * 1000 + (x[7] - 48) * 100 + (x[8] - 48) * 10 + (x[9] - 48);
  if (yy < 2013 || yy > 2015) return false;
  if (dd > mon[mm] || dd <= 0) return false;
  return true;
}
int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    string st = "";
    for (int j = i; j < i + 10; j++) {
      st += s[j];
    }
    if (find(st)) {
      if (u[st] == 0) ans[++c] = st;
      u[st]++;
    }
  }
  for (int i = 1; i <= c; i++) {
    if (u[ans[i]] > mx) {
      mx = u[ans[i]];
      mxs = ans[i];
    }
  }
  cout << mxs;
  return 0;
}

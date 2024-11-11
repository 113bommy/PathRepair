#include <bits/stdc++.h>
using namespace std;
string s, t;
vector<string> tim;
int vis[24][60];
void fill(int a, int b) {
  if (a > 23 || b > 59) return;
  if (vis[a][b]) return;
  vis[a][b] = 1;
  string x = "", y = "";
  stringstream ss1, ss2;
  ss1 << a;
  ss2 << b;
  string h = ss1.str();
  string m = ss2.str();
  if (h.size() == 1)
    x += ('0' + h);
  else
    x += h;
  if (m.size() == 1)
    x += ('0' + m);
  else
    x += m;
  string res = "";
  res += x + y;
  tim.push_back(res);
  fill(a + 1, b);
  fill(a, b + 1);
}
int main() {
  fill(0, 0);
  sort(tim.begin(), tim.end());
  cin >> t >> s;
  if (t == s) {
    cout << t << endl;
    return 0;
  }
  s.erase(2, 1);
  t.erase(2, 1);
  int x = find(tim.begin(), tim.end(), s) - tim.begin();
  int y = find(tim.begin(), tim.end(), t) - tim.begin();
  string A = "", B = "";
  A += tim[1440 - max(x, y) + min(x, y)];
  B += tim[abs(x - y)];
  if (x > y) {
    for (int i = 0; i < A.size(); i++) {
      if (i == 1)
        cout << A[i] << ':';
      else
        cout << A[i];
    }
    cout << endl;
  } else {
    for (int i = 0; i < B.size(); i++) {
      if (i == 1)
        cout << B[i] << ':';
      else
        cout << B[i];
    }
    cout << endl;
  }
  return 0;
}

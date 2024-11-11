#include <bits/stdc++.h>
using namespace std;
string generateOne(int i, int x) {
  int b = x / 2;
  char temp[100];
  sprintf(temp, "((1-abs((t-%d)))+abs((abs((t-%d))-1)))", i, i);
  string s(temp);
  sprintf(temp, "(%d*%s)", b, s.c_str());
  string res(temp);
  return res;
}
string generate(int n, const vector<int> &vals) {
  string res = "";
  for (int i = 0; i < n; i++) {
    string ff = generateOne(i, vals[i]);
    if (i == 0)
      res = ff;
    else {
      res = "(" + res + "+" + ff + ")";
    }
  }
  return res;
}
int main() {
  int n, r;
  scanf("%d", &n);
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> r;
  }
  string f = generate(n, x);
  string g = generate(n, y);
  cout << f << endl << g << endl;
  return 0;
}

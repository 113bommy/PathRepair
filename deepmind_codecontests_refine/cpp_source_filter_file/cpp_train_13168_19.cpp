#include <bits/stdc++.h>
using namespace std;
long int sell[100002] = {0}, buy[100002] = {0};
int main() {
  int n, s, p, q;
  char c;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> c >> p >> q;
    if (c == 'S') {
      sell[p] += q;
    } else
      buy[p] += q;
  }
  int w, r;
  w = s;
  r = s;
  vector<string> vec;
  for (int i = 0; i <= 100000; i++) {
    string str;
    if (w && sell[i]) {
      str += "S ";
      int k = i;
      stringstream ss;
      ss << k;
      string st = ss.str();
      str += st;
      long int w = sell[i];
      stringstream ss2;
      ss2 << w;
      string st2 = ss2.str();
      str += " " + st2;
      vec.push_back(str);
      w--;
    }
  }
  reverse(vec.begin(), vec.end());
  for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
    cout << *it << endl;
  for (int i = 100000; i >= 0; i--) {
    if (r && buy[i]) {
      cout << "B " << i << " " << buy[i] << endl;
      r--;
    }
  }
}

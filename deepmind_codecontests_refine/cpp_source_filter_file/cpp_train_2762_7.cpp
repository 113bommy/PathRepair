#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  getline(cin, str);
  istringstream iss(str);
  int n;
  iss >> n;
  vector<long long int> c(11, 0);
  for (int i = 1; i < 11; ++i) c[i] = c[i - 1] * 10 + 10;
  set<string> p;
  vector<string> res(13100);
  for (int i = 1989; i < 13099; ++i) {
    int cnum = i;
    string cns = "";
    while (cnum) {
      int d = cnum % 10;
      char dc = d + '0';
      cns = dc + cns;
      if (p.find(cns) == p.end()) {
        p.insert(cns);
        res[i] = cns;
        break;
      }
      cnum -= d;
      cnum /= 10;
    }
  }
  for (int i = 0; i < n; ++i) {
    getline(cin, str);
    string numstr = str.substr(str.find('\'') + 1);
    istringstream iss(numstr);
    long long int num;
    iss >> num;
    if (p.find(numstr) != p.end()) {
      auto it = find(res.begin(), res.end(), numstr);
      cout << it - res.begin() << endl;
    } else {
      auto it = lower_bound(c.begin(), c.end(), num - 1989);
      auto dist = distance(c.begin(), it);
      if (dist < int(numstr.size()) || numstr[0] == '0') {
        cout << "1";
      }
      cout << numstr << endl;
    }
  }
  return 0;
}

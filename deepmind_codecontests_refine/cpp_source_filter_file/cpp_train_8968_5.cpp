#include <bits/stdc++.h>
using namespace std;
using li = long int;
int main() {
  string s1;
  cin >> s1;
  vector<char> s(s1.begin(), s1.end());
  li double_v = 0;
  int pv = 0;
  vector<li> dv;
  for (vector<char>::iterator i = s.begin(); i != s.end(); ++i) {
    if (*i == 'o') {
      dv.push_back(double_v);
      pv = 0;
    }
    if (*i == 'v') {
      if (pv == 0) {
        pv = 1;
      } else {
        double_v += 1;
      }
    }
  }
  li total_dv = double_v;
  long long int total = 0;
  for (vector<li>::iterator i = dv.begin(); i != dv.end(); ++i) {
    total += (total_dv - *i) * (*i);
  }
  cout << total << "\n";
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  string s1, s2;
  cin >> s1 >> s2;
  string ss1, ss2, ss3, ss4;
  ss1.push_back(s1[0]);
  ss1.push_back(s1[1]);
  ss2.push_back(s1[3]);
  ss2.push_back(s1[4]);
  ss3.push_back(s2[0]);
  ss3.push_back(s2[1]);
  ss4.push_back(s2[3]);
  ss4.push_back(s2[4]);
  int h1, h2, m1, m2;
  h1 = stoi(ss1);
  m1 = stoi(ss2);
  h2 = stoi(ss3);
  m2 = stoi(ss4);
  int v1, v2;
  v1 = h1 * 60 + m1;
  v2 = h2 * 60 + m2;
  int mid = abs(v2 - v1) / 2;
  int val = min(v1, v2) + mid;
  if ((val / 60) / 10 == 0) {
    if ((val % 60) / 10 == 0) {
      cout << "0" << val / 60 << ":"
           << "0" << val % 60 << endl;
    } else
      cout << "0" << val / 60 << ":" << val % 60 << endl;
  } else {
    if ((val % 60) / 10 == 0) {
      cout << "0" << val / 60 << ":"
           << "0" << val % 60 << endl;
    } else
      cout << val / 60 << ":" << val % 60 << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  map<string, long long int> m1;
  m1["111111"] = 30;
  m1["11112"] = 15;
  m1["1122"] = 8;
  m1["1113"] = 5;
  m1["114"] = 2;
  m1["123"] = 3;
  m1["222"] = 6;
  m1["15"] = 1;
  m1["24"] = 2;
  m1["33"] = 2;
  m1["6"] = 1;
  int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
  for (int i = 0; i < 6; i++) {
    if (s[i] == 'R')
      a++;
    else if (s[i] == 'O')
      b++;
    else if (s[i] == 'Y')
      c++;
    else if (s[i] == 'G')
      d++;
    else if (s[i] == 'B')
      e++;
    else
      f++;
  }
  vector<long long int> v;
  if (a != 0) v.push_back(a);
  if (b != 0) v.push_back(b);
  if (c != 0) v.push_back(c);
  if (d != 0) v.push_back(d);
  if (e != 0) v.push_back(e);
  if (f != 0) v.push_back(f);
  sort(v.begin(), v.end());
  char c1;
  string s1 = "";
  for (int i = 0; i < v.size(); i++) {
    s1 += (v[i] - 208);
  }
  cout << m1[s1];
}

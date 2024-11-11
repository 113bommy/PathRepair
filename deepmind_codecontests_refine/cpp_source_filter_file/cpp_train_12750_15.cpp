#include <bits/stdc++.h>
using namespace std;
string to[1111];
int main() {
  to['0'] = "";
  to['1'] = "";
  to['2'] = "2";
  to['3'] = "3";
  to['4'] = "322";
  to['5'] = "5";
  to['6'] = "532";
  to['7'] = "7";
  to['8'] = "7222";
  to['9'] = "733222";
  int n;
  scanf("%d", &n);
  string s1;
  cin >> s1;
  string s2 = "";
  for (int i = 0; i < s1.size(); i++) s2 += to[s1[i]];
  sort(s2.begin(), s2.end(), greater<int>());
  cout << s2 << endl;
}

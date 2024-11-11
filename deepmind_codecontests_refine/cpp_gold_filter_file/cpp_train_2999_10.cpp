#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  bool flag;
 
  cin >> s;
 
  sort(s.begin(),s.end());
 
  flag = (s[0]==s[1])&(s[1]!=s[2])&(s[2]==s[3]);
 
  cout << (flag?"Yes":"No") << endl;}
#include<bits/stdc++.h>
using namespace std;
int main()
{
string s,t;
  cin >> s >> t;
  for(int i=0;i<t.size();++i)
  {
  cout << s.at(i) << t.at(i);
  }
  if(t.size<s.size()) cout << s.at(s.size()-1);
return 0;}
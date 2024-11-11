#incldue<bits/stdc++.h>
using namespace std;
int main()
{
string s;
  cin >> s;
int ans=0;
  for(int i=0;i<s.size()-1;++i)
  {
  if(s.at(i)!=s.at(i+1)) ans++;
  }
  cout << ans;
return 0;}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin>>s;
  if(s[s.size()-1]=='s'){
    cout<<s<<"es";
  }
  else{
    cout<<s<<'s';
  }
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
  bool N=0,S=0,E=0,W=0;
  string A;
  cin >> A;
  for(int i=0;i<A.size();i++)
  {
    char b=A.at(i);
    if(b=='N')N=1;
    else if(b=='S')S=1;
    else if(b=='E')E=1;
    else if(b=='W')W=1;
  }
  if(N==S&&E==W)cout << "Yes" << endl;
  else{
    cout << "No" << endl;
  }
}
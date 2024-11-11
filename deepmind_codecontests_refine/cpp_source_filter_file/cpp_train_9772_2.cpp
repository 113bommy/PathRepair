#include<bits/stdc++.h>
using namespace std;
int main()
{
  bool N=0,S=0,E=0,W=0;
  string S;
  cin >> S;
  for(int i=0;i<S.size();i++)
  {
    char b=S.at(i);
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
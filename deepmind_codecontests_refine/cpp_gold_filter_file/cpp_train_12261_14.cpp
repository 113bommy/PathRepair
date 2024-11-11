#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int k=0;
  int ma=0;
  for(int i=0;i<3;i++)
  {if(s[i]=='R')
      k++;
   else
     k=0;
   ma=max(ma,k);
  }
  cout<<ma;
}
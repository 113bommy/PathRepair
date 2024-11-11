#include <bits/stdc++.h>
using namespace std;
int main()
{  
   int n,m,s=0;
  cin>>n>>m;
  while(m--)
  {
     int x;
    fin>>x;
    s+=x;
  }
  if(s>n)cout<<-1;
  else cout<<n-s;
}
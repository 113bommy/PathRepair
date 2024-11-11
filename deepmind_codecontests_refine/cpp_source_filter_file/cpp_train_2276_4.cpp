#include<bits/stdc++.h>
using namespace std;
long long  e[100002];
int main()
{
  long long a,b,c,d=0;
  cin>>a>>b>>c;
  for(i=1;i<=a;i++)
  {
  	 cin>>e[i];
  	 if(e[i]<b||e[i]>=c)
  	   d++;
  }
   cout<<d;
  cout<<endl;		
} 
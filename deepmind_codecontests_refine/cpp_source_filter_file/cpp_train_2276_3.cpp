#include<bits/stdc++.h>
using namespace std;
long long  a[100002];
int main()
{
  long long a,b,c,d=0;
  cin>>a>>b>>c;
  for(i=1;i<=a;i++)
  {
  	 cin>>a[i];
  	 if(a[i]<b||a[i]>=c)
  	   d++;
  }
   cout<<d;
  cout<<endl;		
} 
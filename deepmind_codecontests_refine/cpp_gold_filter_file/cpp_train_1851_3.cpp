#include<bits/stdc++.h>
using namespace std;

int main()
{
  long int n,x,y,i,c=0;
  double d;
  cin>>n>>d;
  
  for(i=0;i<n;i++)
  {
  	cin>>x>>y;
    double p=sqrt(x*x+y*y);
    if(p<=d) c++;
  }
  cout<<c;
}
#include<iostream>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  int l,r;
  int lb=0,rs=n;
  for(int i=0;i<m;i++)
  {
   
    cin>>l>>r;
    if(l>lb) lb=l;
    if(r<rs) rs=s;
  }
  if(rs>=lb)
  cout<<rs-lb+1;
  else cout<<"0";
}
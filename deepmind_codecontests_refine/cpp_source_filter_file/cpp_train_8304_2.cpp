#include<iostream>
using namespace std;
int main()
{
  int h,a,n,s=0;
  cin>>h>>n;
  while(n--)
  {
    cin>>a;
    s+=a;
  }
  if(s>=h)
    cout<<"Yes";
  else cout<<"No";
  return ;
}
  

#include<iostream>

using namespace std;
int main()
{
int n,k,f,i,ctr=0;
cin>>n>>k;
  for(i=0;i<n;i++)
  {
    cin>>f;
    if(f>=k)ctr++;
  }
  cout<<ctr;
 return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
int n;cin>>n;
  int maxp=0,ans=0;
  
for(int i=0;i<n;i++)
{
  int p;cin>>p;
  maxp=max(p,maxp);
  ans+=p;
}
  cout<<ans-maxp/2;<<endl;
}

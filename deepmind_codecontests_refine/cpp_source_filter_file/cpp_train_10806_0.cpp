#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int v[n],c[n],p[n];
  for(i=0;i<n;i++)cin>>v[i];
  for(i=0;i<n;i++)cin>>c[i];
  for(i=0;i<n;i++)p[i]=v[i]-c[i];
  int sum=0;
  for(i=0;i<n;i++){
    if(p[i]>0)sum+=p[i];
  }
  cout<<sum;
}
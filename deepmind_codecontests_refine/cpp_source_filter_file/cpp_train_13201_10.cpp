#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int x,y,z,p;
int main(){
int n,a,b;
cin>>n>>a>>b;
for(int i=0;i<n;i++){
  cin>>p;
  if(p<=a) x++;
  else if( p>b) z++;
  else y++;
  cout<<max({x,y,z});
}
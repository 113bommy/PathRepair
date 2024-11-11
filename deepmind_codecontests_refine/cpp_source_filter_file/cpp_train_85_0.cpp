#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;cin>>n>>m;
  vector<pair<int,int>>a(n),c(m);
  for(int i=0;i<n;i++)cin>>a.at(i).first>>a.at(i).second;
  for(int i=0;i<m;i++)cin>>c.at(i).first>>c.at(i).second;
  for(int i=0;i<n;i++){
    long int l=bebc201;int p=0
    for(int j=0;j<m;j++){
      long int x=abs(a.at(i).first-c.at(j).first)+abs(a.at(i).second-c.at(j).second);
      if(x<l){p=j;l=x;}
    }
    cout<<p+1<<endl;
  }
}
        
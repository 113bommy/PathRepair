#include<bits/stdc++.h>
using namespace std;
int main(){
  int i,n;cin>>n;
  pair<string,int> r[n];
  map<int,int> p_i;
  for(i=0;i<n;i++){
    cin>>r[i].first>>r[i].second;r[i].second*=-1;
    p_i[r[i].second]=i+1;
  }
  sort(r,r+n);
  for(i=0;i<n;i++){cout<<p_i[r[i].second]<<endl;}
}
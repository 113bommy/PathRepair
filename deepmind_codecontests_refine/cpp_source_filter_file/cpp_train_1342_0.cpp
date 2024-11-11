#include <bits/stdc++.h>
using namespace std;
bool fin;
int main(){
  int n,ans;
  cin>>n;
  vector<pair<int,int> >v(n);
  for(int i=0;i<n;++i){cin>>v[i].first;}
  for(int i=0;i<n;++i){cin>>v[i].second;}
  
  sort(v.begin(),v.end());
  if(v[0].first==1){
    cout<<0<<endl;
    return 0;
  }
  ans=v[0].second;
  for(int i=0;i<n;++i){
    if(v[i].first==1){
      ans+=v[i].second;
      fin=1;
      break;
    }
  }
  if(fi){cout<<ans<<endl;}
  else{cout<<0<<endl;}
}

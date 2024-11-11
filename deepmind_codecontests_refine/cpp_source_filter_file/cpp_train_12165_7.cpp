#include<bits/stdc++.h>
using namespace std;

int main(){
  long long N,K,key=0;
  cin>>N>>K;
  vector<pair<int,int> >v(n);
  for(int i=0;i<N;i++){
    cin>>v[i].first>>v[i].second;
  }
  sort(v.begin(),v.end());
  for(int i=0;i<N;i++){
    key+=v[i].second;
    if(key>=K){
      cout<<v[i].first<<endl;
      break;
    }
  }
  return 0;
}

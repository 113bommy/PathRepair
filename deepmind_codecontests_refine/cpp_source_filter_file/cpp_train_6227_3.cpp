#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  long long ans=0;
  vector<pair<long,long>> drink(n);
  for(int i=0;i<n;i++){
    long a,b;
    cin>>a>>b;
    drink[i]=make_pair(a,b);
  }
  sort(drink.begin(),drink.end());
  int k=0;
  while(m>0){
    ans+=(drink[k].first)*min(m,drink[k].second);
    m-=drink[k].second;
    k++;
  }
  cout<<ans;
}
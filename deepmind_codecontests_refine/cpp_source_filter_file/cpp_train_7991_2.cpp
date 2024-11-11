#include<bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int main(){
  ll N,K;
  cin>>N>>K;
  vector<ll> A(N);
  for(ll i=0;i<N;i++;)cin>>A.at(i);
  ll left=0;
  ll right=1000000001;
  while(right-left>1){
    ll mid=(right+left)/2;
    ll time=0;
    for(ll i=0;i<N;i++)time+=(A.at(i)-1)/mid;
    if(time>K)left=mid;
    else right=mid;
  }
  cout<<right<<endl;
}
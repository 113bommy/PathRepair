#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int d[2]={2,8},ans=-1;
vector<ll> v;

void func(int x,ll k){
  if(x) v.push_back(k);
  if(x==18) return ;
  for(int i=0;i<2;i++) func(x+1,k*10+d[i]);
}

void func2(int x,ll k,int sum){
  if(k==1&&sum) ans=max(ans,sum);
  if(v[x]>k) return ;
  if(!(k%v[x])) func2(x,k/v[x],sum+1);
  if(x+1!=v.size()) func2(x+1,k,sum);
}

int main(){
  ll n;
  cin>>n;
  func(0,0);
  sort(v.begin(),v.end());
  func2(0,n,0);
  cout<<ans<<endl;
  return 0;
}
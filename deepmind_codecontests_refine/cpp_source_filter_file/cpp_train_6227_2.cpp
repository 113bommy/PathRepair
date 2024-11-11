#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll
using namespace std;

int main(){
	int n,m,k=0;cin>>n>>m;
  	ll ans=0;
  	vector<pair<ll,ll>> v(n);
  	for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
  	sort(v.begin(),v.end());
  	while(m){
      	ll t=v[k].second;
    	if(m>=t)
        {m-=t;
      	ans+=t*v[k].first;}
      	else
        {m=0;ans+=m*v[k].first;}
      	k++;
    }
  	cout<<ans;
}
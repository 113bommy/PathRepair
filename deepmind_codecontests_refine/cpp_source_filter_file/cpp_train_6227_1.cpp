#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,m,i,j,ans=0;
  	cin>>n>>m;
  	vector<pair<ll,ll>> a(n);
 	for(i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
    }

  	sort(a.begin(),a.end());
  	
  	for(i=0;i<n;i++){
		if(a[i].second<m){
          m-=a[i].second;
          ans+=(a[i].first)*(a[i].second);
        }else{
		  ans+=m*(a[i].first);
          break;
        }
    }

  	cout<<ans<endl;
}
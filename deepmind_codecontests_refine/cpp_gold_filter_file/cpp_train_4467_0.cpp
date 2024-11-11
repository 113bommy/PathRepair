#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef double db;
ll n;
vector<P> v;//first ???????????? second: 0or1
ll x;
int main()
{while(1){
	cin>>n;
	if(!n) return 0;
	v.clear();
	for(ll i=1;i<=n;i++){
		cin>>x;
		if(i==1||(i%2==1 && v[v.size()-1].second!=x)){//??°??????
			v.push_back(P(i,x));
		}
		else if(i%2==0&&v[v.size()-1].second!=x){//???????¶????
			if(v.size()==1){
				v[0].second=x;
			}
			else{
				v.erase(v.end()-1);
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<v.size();i++){
		if(v[i].second==0) ans+=(i==v.size()-1?n+1:v[i+1].first)-v[i].first;
	}
	cout<<ans<<endl;
}}
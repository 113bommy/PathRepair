#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string,pair<ll,ll>>p[214514];

int main(){
	ll n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].first>>p[i].second.first;
		p[i].second.first*=-1;
		p[i].second.second=i+1;
	}
	sort(p,p+n);
	for(int i=0;i<n;i++)cout<<p[i].second.second<<endl;
	return 0;
}

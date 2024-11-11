#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	long long n,m;
	while(cin>>n>>m,n){
		vector<pair<int,pair<int,int> > >v;
		pair<int,pair<int,int> >p;
		long long a[20001]={0},t,s=0;
		a[1]=1;
		r(i,m){
			cin>>p.first>>p.second.first>>p.second.second;
			v.push_back(p);
		}
		sort(v.begin(),v.end());
		r(i,m)if(a[v[i].second.first])a[v[i].second.second]=1;
		r(i,n+1)if(a[i])s++;
		cout<<s<<endl;
	}
}
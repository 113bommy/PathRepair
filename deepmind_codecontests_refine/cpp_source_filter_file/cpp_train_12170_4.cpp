#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;
ll red[100];
ll blue[100];
ll le[100];
ll ri[100];

ll gcd(ll a,ll b){
	if(b>a){	a^=b;	b^=a;	a^=b;	}
	while(1){
		int temp=a%b;
		if(temp==0)	break;
		a=b;	b=temp;
	}
	return b;
}

ll dfs(int now){
	ll l=1,r=1;
	if(le[now]!=0)	l*=dfs(le[now]-1);
	if(ri[now]!=0)	r*=dfs(ri[now]-1);
	ll g=gcd(blue[now]*r,red[now]*l);
	l
	l ans=blue[now]*r*red[now]*l/g;
	return ans/blue[now]+ans/red[now];	
}
	
int main(){
	while(true){
		cin>>n;
		if(n==0)	return 0;
		vector<int> parent(n,-1);
		for(int i=0;i<n;i++){
			cin>>red[i]>>blue[i]>>le[i]>>ri[i];
			if(le[i]!=0)	parent[le[i]-1]=i;	
			if(ri[i]!=0)	parent[ri[i]-1]=i;
		}
		for(int i=0;i<n;i++){
			if(parent[i]==-1){
				cout<<dfs(i)<<endl;
				break;
			}
		}
	}
	return 0;
}
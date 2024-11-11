#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,px,y;
int main(){
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x&1)y=1;
	}
	if(y)cout<<(1LL<<(n-1));
	else if(p==0)cout<<(1LL<<n);
	else cout<<0;
}
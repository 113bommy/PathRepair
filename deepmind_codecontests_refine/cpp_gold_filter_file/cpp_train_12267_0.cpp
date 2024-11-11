#import <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n,k;cin>>n>>k;
	if(k==0)cout<<n*n<<endl,exit(0);
		int ans=0;
	for(int i=k+1;i<=n;i++){
		int m=n/i;
		ans+=m*(i-k)+max(0ll,n%i-k+1);
	}
	cout<<ans<<endl;
}

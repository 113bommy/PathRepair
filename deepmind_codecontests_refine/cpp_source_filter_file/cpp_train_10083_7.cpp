#include<bits/stdc++.h>
using namespace std;
long long n,a,b,ans;
long long x[100005],;
int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
    	cin>>x[i]; 
	}
    for(int i=1;i<n;i++){
    	ans+=min(a*(x[i+1]-x[i]),b);
	}
    cout<<ans<<endl;
    return 0; 
}